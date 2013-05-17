#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv) 
{
    char buf[256];
    strncpy(buf, "frack", sizeof "frack");
    printf("buf: %s\n", buf);

    char frack[] = "me";
    printf("frack: %s %zd\n", frack, sizeof frack);

    //char* foo = realloc(frack, sizeof "off");
    //realloc(frack, 4);
    char* duck;
    duck = "me";
    printf("duck: %s %zd\n", duck, sizeof duck);

    char* puck;
    puck = malloc(sizeof "goo");
    puck = "goo";
    // this fails because "goo" is in the stack, so puck points to a stack object; realloc complains at runtime because it wasn't a heap object
    //puck = realloc(puck, sizeof "patata");
    //puck = "patata";
    printf("puck: %s %zd\n", puck, sizeof puck);

    return 0;
}

