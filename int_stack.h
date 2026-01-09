#ifndef INT_STACK_H
#define INT_STACK_H

#include <stdbool.h>

#define INT_STACK_MAX 100

typedef struct {
    int stack[INT_STACK_MAX];
    int top;
} IntStack;

void int_stack_init(IntStack* s);
bool int_stack_is_empty(IntStack* s);
bool int_stack_is_full(IntStack* s);
void int_stack_push(IntStack* s, int value);
int int_stack_pop(IntStack* s);
int int_stack_peek(IntStack* s);

#endif
