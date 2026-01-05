#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


void queue_init(Queue* q) {
    q->head = 0;
    q->tail = 0;
}

bool queue_is_empty(Queue* q) {
    return q->head == q->tail;
}

bool queue_is_full(Queue* q) {
    return q->tail == MAX;
}

void enqueue(Queue* q, char c) {
    if (queue_is_full(q)) {
        printf("Queue overflow\n");
        exit(EXIT_FAILURE);
    }

    q->queue[(q->tail)++] = c;
}

char dequeue(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    return q->queue[(q->head)++];
}


