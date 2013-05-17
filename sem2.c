/* creazione di due semafori con potenziale deadlock
 */
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define	SEMKEY 	75
#define S1 	0
#define	S2	0

int semid;
unsigned int count;

struct sembuf psembuf, vsembuf;

main (int argc, char **argv) {
	int i, sem1, sem2;
	short initvec[2], outvec[2];

	if ( argc == 1 ) { 
		semid = semget(SEMKEY, 2, 0777|IPC_CREAT);
		initvec[0] = initvec[1] = 1;
		semctl (semid, SETALL, initvec[0]);
		semctl (semid, GETALL, outvec[0]);
		printf ("semaphore init values: %d %d\n", outvec[0],
				outvec[1]);
		pause();
	}
	else if ( ! strcmp (argv[1],"0") ) {
		sem1 = S1;
		sem2 = S1;
	}
	else {
		sem1 = S2;
		sem2 = S1;
	}

	semid = semget (SEMKEY, 2, 0777);
	psembuf.sem_op = -1;	// P
	psembuf.sem_flg = SEM_UNDO;
	vsembuf.sem_op = 1;	// V
	vsembuf.sem_flg = SEM_UNDO;
	for ( count = 0 ; ; count++ ) {
		psembuf.sem_num = sem1;
		semop (semid, &psembuf, 1);	// P(s1)
		printf ("p(s1)\n");
		psembuf.sem_num = sem2;
		semop (semid, &psembuf, 1);	// P(s2)
		printf ("\tp(s2)\n");
//		printf ("proc %d - count %d\n", getpid(), count);
		printf ("resource usage: %d\n", psembuf.sem_num);
		vsembuf.sem_num = sem2;
		semop(semid, &vsembuf, 1);	// V(s1)	XXX
		printf ("\tv(s2)\n");
		vsembuf.sem_num = sem1;
		semop(semid, &vsembuf, 1);	// V(s2)	XXX
		printf ("v(s1)\n");
		sleep (2);
	}
}
