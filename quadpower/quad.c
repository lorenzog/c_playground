#include <math.h>
#include <stdio.h>

int main ( int argc, char **argv )
{
    int i;
    double pows[100];
    for ( i = 0 ; i < 100 ; i++ )
    {
        pows[i] = pow(i, i);
        printf("%d: %f\n", i, pows[i]);
    }
    //double sums[i*(i-1)]; // 100 + 99 + 98 + .. + 1 
    int j, count = 0;
    double sums[100][100]; // non optimized: it's actually 5050, not 10000
    for ( i = 0 ; i < 100 ; i++ )
        for ( j = i+0 ; j < 100 ; j++ )
            //sums[count++] = pows[i] + pows[j];
            sums[i][j] = pows[i] + pows[j];
    printf("i: %d, j: %d, count: %d\n", i, j, count);

    return 0;
}
