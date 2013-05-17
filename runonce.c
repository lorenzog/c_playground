#include <stdio.h>

typedef int f_foo(int);

f_foo foo;

int main(void) {
    int i;

    i = 0;
    i += foo(42);
    i += foo(13);
    i += foo(4);
    printf("Total: %d\n", i);
    return 0;
}

int foo(int x) {
    static int done = 0;
    if(!done)
    {
        printf("Run-once done!\n");
        done = 1;
    }
    printf("%d\n", x);
    return x;
}
