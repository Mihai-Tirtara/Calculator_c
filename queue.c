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

void queue_enque(Queue* q, char c) {
    if (queue_is_full(q)) {
        printf("Queue overflow\n");
        exit(EXIT_FAILURE);
    }

    q->queue[(q->tail)++] = c;
}

char queue_deque(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    return q->queue[(q->head)++];
}

char queue_peek(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    return q->queue[q->head];
}

char* queue_to_string(Queue* q) {
    static char buffer[MAX * 2 + 3];
    int pos = 0;

    buffer[pos++] = '[';

    for (int i = q->head; i < q->tail; i++) {
        if (i > q->head) {
            buffer[pos++] = ' ';
        }
        buffer[pos++] = q->queue[i];
    }

    buffer[pos++] = ']';
    buffer[pos] = '\0';

    return buffer;
}


