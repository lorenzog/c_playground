/*
 * my implementation of a message queue
 */

#include <stdlib.h>
#include <stdio.h>
#include "msgqueues.h"

message* buildNode (int value) {
	message* tmp;
	tmp = (message*)malloc(sizeof(message));

	tmp->posx = value;
	tmp->next = NULL;
	tmp->prev = NULL;

	printf("build node with value: %f\n", tmp->posx);
	return(tmp);
}

void addNodeToQueue(message* m, msgqueue* q) {
	if ( q->head == NULL && q->tail == NULL )
		// first node in chain
		q->tail = m;
	else
		// NULL has no ->prev!
		q->head->prev = m;

	m->next = q->head;
	q->head = m;
	q->count++;
}

message* readNode(msgqueue* q) {
	q->count--;
	if ( q->tail->prev == NULL )
	{
		message* tmp = q->tail;
		q->tail = NULL;
		return (tmp);
	}
	q->tail = q->tail->prev;
	return (q->tail->next);
}

int main(int argc, char* argv[]) {
	msgqueue*	q;
	message*	m;

	q = (msgqueue*)malloc(sizeof(msgqueue));
	m = (message*)malloc(sizeof(message));

	int i;

	// queue init
	q->head = NULL;
	q->tail = NULL;
	q->count = 0;

	for ( i = 1 ; i < argc ; i++ )
	{
		m = buildNode(atoi(argv[i]));
		addNodeToQueue(m, q);
		printf("\n");
	}

	printf("reading %d count\n", q->count);

	while ( q->tail != NULL )
	{
		m = readNode(q);
		printf("last node read has value %f\n", m->posx);
	}

	free(q);
	free(m);

	return(0);
}

