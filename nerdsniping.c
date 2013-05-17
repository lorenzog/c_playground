#include <stdio.h>
#define POW2(a) (a)*(a)

int main() 
{
	int a = 2;
	int b = POW2(a++);
	int c = POW2(++a);
	printf("%d %d\n", b, c);
}
