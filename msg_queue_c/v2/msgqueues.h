/*
 * the header file for my impl of msg queues
 */

typedef struct message {
	int		msgnum;	// a counter 
	float		posx;
	float		posy;
	float		posa;	// the rotation in rads 
	struct message* 	next;	// the next message 
	struct message*		prev;	// the previous message 
} message ;

typedef struct msgqueue {
	struct 	message* 	head;
	struct 	message*	tail;
	int	count;
} msgqueue ;
