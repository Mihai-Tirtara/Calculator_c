#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX 100

typedef struct {
    char queue[MAX];
    int head;
    int tail;
} Queue;

void queue_init(Queue* q);
bool queue_is_empty(Queue* q);
bool queue_is_full(Queue* q);
void queue_enque(Queue* q, char c);
char queue_deque(Queue* q);
char queue_peek(Queue* q);
char* queue_to_string(Queue* q);

#endif 
