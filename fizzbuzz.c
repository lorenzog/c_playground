#include <stdio.h>

int main(int argc, char **argv) 
{
    int i;
    for ( i = 1 ; i <= 100 ; i++ )
    {
        if ( i % 3 && i % 5 )
            printf("%d", i);
        if ( i % 3 == 0)
            printf("Fizz");
        if ( i % 5 == 0 )
            printf("Buzz");
        printf("\n");
    }
    return 0;
}
