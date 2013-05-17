/*
 * the header file for my impl of msg queues
 */

struct msg {
	int 	x;
	struct msg*	prev;
	struct msg*	next;
};

struct queue {
	struct msg*	head;	// where new messages enter
	struct msg*	tail;	// where old messages are read from
	int nodes;
};

