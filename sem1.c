/*
 * semaphore demonstration
 * usage: ./sem1 1 & ./sem1
 * where '1' is a parameter (to start the whole semaphore)
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

// prototypes
static int set_semvalue(void);
static void del_semvalue(void);
static int semaphore_p(void);		// P: wait (acq lock or wait)
static int semaphore_v(void);		// V: signal (free sem)
static int sem_id;

// requested to be defined in <bits/sem.h>
#ifdef _SEM_SEMUN_UNDEFINED
union semun {
     int val;                           // value for SETVAL
     struct semid_ds *buf;              // buffer for IPC_STAT & IPC_SET
     unsigned short int *array;         // array for GETALL & SETALL
     struct seminfo *__buf;             // buffer for IPC_INFO
};
#endif
int main(int argc, char *argv[]) {
	int i;
	int pause_time;
	char op_char = 'O';

	// initialize the random seed
	srand( (unsigned int) getpid() );

	// creates a new semaphore (only 1) with modes + create if doesn't ex
	sem_id = semget( (key_t)1234, 1, 0666 | IPC_CREAT);

	// if invoked with parameters (must be the first invocation)
	if ( argc > 1 ) {
		if ( ! set_semvalue() ) {
			fprintf (stderr, "failed to init semaphore\n");
			exit (EXIT_FAILURE);
		}
		op_char = 'X';
		// gives time to start the second semaphore		
		sleep (2);
	}

	// normal run
	for ( i = 0 ; i < 10 ; i++ ) {
		if ( !semaphore_p() )
			exit (EXIT_FAILURE);
		printf ("%c", op_char); 
		fflush (stdout);
		
		pause_time = rand() % 3;
		sleep (pause_time);
		printf("%c", op_char);
		fflush (stdout);

		if ( ! semaphore_v() )
			exit (EXIT_FAILURE);
		pause_time = rand() % 2;
		sleep (pause_time);
	}

	printf ("\n%d - finished\n", getpid() );
	if (argc > 1 ) { 
		sleep (10);
		del_semvalue();
	}
	exit (EXIT_SUCCESS);
}

static int set_semvalue (void) {
	union semun sem_union;

	sem_union.val = 1;
	if ( semctl ( sem_id, 0, SETVAL, sem_union ) == -1 )
		return (0);
	return (1);
}

static void del_semvalue (void) {
	union semun sem_union;

	if ( semctl ( sem_id, 0, IPC_RMID, sem_union ) == -1 )
		fprintf (stderr, "failed to delete semaphore\n");
}

static int semaphore_p (void) {
	struct sembuf sem_b;

	sem_b.sem_num = 0;
	sem_b.sem_op = -1; 	// P
	sem_b.sem_flg = SEM_UNDO;
	if ( semop ( sem_id, &sem_b, 1 ) == -1) {
		fprintf (stderr, "semaphore_p failed\n");
		return (0);
	}
	return (1);
}

static int semaphore_v(void) {
	struct sembuf sem_b;

	sem_b.sem_num = 0;
	sem_b.sem_op = 1;	// V
	sem_b.sem_flg = SEM_UNDO;
	if ( semop ( sem_id, &sem_b, 1 ) == -1 ) {
		fprintf (stderr, "semaphore_v failed\n");
		return (0);
	}
	return (1);
}
