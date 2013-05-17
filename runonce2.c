#include <stdio.h>

typedef int f_foo(int);

f_foo foo_runonce;
f_foo foo_runonce_done;
f_foo * foo = foo_runonce;

int main(void) {
    int i;

    i = 0;
    i += foo(42);
    i += foo(13);
    i += foo(4);
    printf("Total: %d\n", i);
    return 0;
}

int foo_runonce(int x) {
    printf("Run-once done!\n");
    foo = foo_runonce_done;
    return foo(x);
}

int foo_runonce_done(int x) {
    printf("%d\n", x);
    return x;
}
