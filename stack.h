#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
} Stack;

void stack_init(Stack* s);
bool stack_is_empty(Stack* s);
bool stack_is_full(Stack* s);
void stack_push(Stack* s, char c);
char stack_pop(Stack* s);
char stack_peek(Stack* s);

#endif
