#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT "24377" // cherr
#define BACKLOG 10
#define MSGLEN 255  // length of incoming message
#define HASH ""

// thanks djb: http://www.cse.yorku.ca/~oz/hash.html
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

// code taken from http://beej.us/guide/bgnet/output/html/multipage/clientserver.html
void sigchld_handler(int s)
{
    while(waitpid(-1, NULL, WNOHANG) > 0);
}

// get sockaddr, ipv4 or ipv6
void *get_in_addr(struct sockaddr *sa)
{
    if ( sa->sa_family == AF_INET )
        return &(((struct sockaddr_in*)sa)->sin_addr);
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}


int main (int argc, char **argv) 
{
    // open simple socket
    int sockfd, new_fd; 
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr;
    socklen_t sin_size;
    struct sigaction sa;
    int yes = 1;
    char s[INET6_ADDRSTRLEN];
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0 )
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return -1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next)
    {
        if ( (sockfd = socket(p->ai_family, p->ai_socktype, 
                        p->ai_protocol) ) == -1)
        {
            perror("server: socket");
            continue;
        }

        if ( setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, 
                    sizeof(int)) == -1 ) 
        {
            perror("setsockopt");
            exit(-1);
        }

        if ( bind(sockfd, p->ai_addr, p->ai_addrlen) == -1 )
        {
            close(sockfd);
            perror("server: bind");
            continue;
        }
        break;
    }

    if ( p == NULL )
    {
        fprintf(stderr, "server: failed to bind\n");
        return -2;
    }
    freeaddrinfo(servinfo);

    // listen with select
    if ( listen(sockfd, BACKLOG) == -1 )
    {
        perror("listen");
        exit(-1);
    }

    sa.sa_handler = sigchld_handler; // reap zombies
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if ( sigaction(SIGCHLD, &sa, NULL) == -1 )
    {
        perror("sigaction");
        exit(-1);
    }

    printf("server: waiting for connections...\n");

    while(1)
    {
        sin_size = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr*) &their_addr,
                &sin_size);
        if ( new_fd == -1 )
        {
            perror("accept");
            continue;
        }

        inet_ntop(their_addr.ss_family,
                get_in_addr((struct sockaddr*) &their_addr),
                s, sizeof s);
        printf("server: got connection from %s\n", s);

        if (!fork()) // child
        {
            close(sockfd);   // no need to listen
            // read string
            unsigned char* datain;
            datain = malloc(sizeof(char) * MSGLEN);
            memset(datain, 0, sizeof(char) * MSGLEN);
            ssize_t read_data = read(new_fd, datain, MSGLEN);
            if ( read_data < 0 )
            {
                perror("read");
                exit(-1);
            }
            printf("read %zd chars: %s ", read_data, datain);
            memset(datain+read_data-1, 0, sizeof(char) * MSGLEN - read_data + 1);
            // hash it
            unsigned long result = hash(datain);
            printf("%zd\n", result);
            // exec qmail-inject + local IRC?
            close(new_fd);
            exit(0);
        }
        close(new_fd);  // parent doesn't need this
    }

    return 0;
}
