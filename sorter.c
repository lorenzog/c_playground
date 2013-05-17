#include <stdio.h>
#include <stdlib.h>

// from: http://www.cprogramming.com/tutorial/function-pointers.html

int sortfunc (const void* a, const void* b)
{
    int first = *(int*) a;
    int second = *(int*) b;

    if ( first < second ) 
        return -1;
    if ( first > second )
        return 1;
    return 0;
}

int main(int argc, char **argv) 
{

    int arr[10] = { 9, 5, 42, 0, -4, 2, 1 };
    int i;

    for ( i = 0 ; i < sizeof arr / sizeof arr[0] ; i++ )
        printf("%d ", arr[i]);
    printf("\n");

    qsort(arr, sizeof arr/sizeof arr[0], sizeof(int), sortfunc);

    for ( i = 0 ; i < sizeof arr / sizeof arr[0] ; i++ )
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
