/*
 * my implementation of a message queue
 */

#include <stdlib.h>
#include <stdio.h>
#include "msgqueues.h"

struct msg* buildNode (int value) {
	struct msg* tmp;
	tmp = malloc(sizeof(tmp));

	tmp->x = value;
	tmp->next = NULL;

	printf("build node with value: %d\n", tmp->x);
	return(tmp);
}

void addNodeToQueue(struct msg* m, struct queue* q) {
	if ( q->head == NULL && q->tail == NULL )
		// first node in chain
		q->tail = m;
	else
		// NULL has no ->prev!
		q->head->prev = m;

	m->next = q->head;
	q->head = m;
	q->nodes++;
}

struct msg* readNode(struct queue* q) {
	if ( q->tail->prev == NULL )
	{
		struct msg* tmp = q->tail;
		q->tail = NULL;
		return (tmp);
	}
	q->tail = q->tail->prev;
	return (q->tail->next);
}

int main(int argc, char* argv[]) {
	struct queue*	q;
	struct msg*	m;

	q = malloc(sizeof(q));
	m = malloc(sizeof(m));

	int i;

	// queue init
	q->head = NULL;
	q->tail = NULL;
	q->nodes = 0;

	for ( i = 1 ; i < argc ; i++ )
	{
		m = buildNode(atoi(argv[i]));
		addNodeToQueue(m, q);
		printf("\n");
	}

	printf("reading %d nodes\n", q->nodes);

	while ( q->tail != NULL )
	{
		m = readNode(q);
		printf("last node read has value %d\n", m->x);
	}

	free(q);
	free(m);

	return(0);
}

