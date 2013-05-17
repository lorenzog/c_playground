/*
 * utilizzo di puntatori e strutture
 *
 */

// for EXIT_FAILURE
#include <stdlib.h>
// for strings
#include <string.h>
// for all the rest
#include <stdio.h>


struct s_parametri {
	char *param;
	int num;
} parametri[10];

void getdata(struct s_parametri *p);
void printdata(struct s_parametri *p);

int main ( int argc, char *argv[]) {

	int count = 0;

	int *mem = malloc (count*sizeof(struct s_parametri));
	if ( mem == NULL ) {
		perror ("malloc failure");
		exit (EXIT_FAILURE);
	}
	for ( count ; count < argc ; count++ ) {
		parametri[count].num = count;
		parametri[count].param = argv[count];
//		getdata(&parametri[count]);
//		printdata(&parametri[count]);
	}
	free (mem);
}

void getdata(struct s_parametri *p) {
//	*p->param = argv[argc];
}

void printdata(struct s_parametri *p) {
	int i = 0;
	for ( i ; i < 2 ; i++ ) {
	printf("param: %s\n", p[i].param);
	printf("num: %i\n", p[i].num);
	}
}
