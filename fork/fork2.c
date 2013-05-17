#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	pid_t	pid;
	char 	*message;
	int	n;
	int	exit_code;
	
	printf ("Fork starting, pid ");
	pid = fork();
	printf ("%d\n", pid);

	switch (pid) {
		case -1:
			exit (1);
		case 0:
			message = "child";
			n = 2;
			exit_code = 37;
			break;
		default:
			message = "parent";
			n = 5; 
			exit_code = 0;
			break;
	}

	for ( ; n > 0 ; n--) {
		printf("%s, pid = %d\n", message, pid);
		sleep(1);
	}

	if ( pid ) {
		int 	stat_val;
		pid_t	child_pid;

		child_pid = wait (&stat_val);

		printf("child has done, PID = %d\n", child_pid);
		if (WIFEXITED(stat_val))
			printf("child exited with code %d\n", 
					WEXITSTATUS(stat_val));
		else
			printf("child terminated abnormally\n");
	}

	exit (exit_code);
}
