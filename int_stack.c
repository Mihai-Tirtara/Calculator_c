#include "int_stack.h"
#include <stdio.h>
#include <stdlib.h>

void int_stack_init(IntStack* s) {
    s->top = -1;
}

bool int_stack_is_empty(IntStack* s) {
    return s->top == -1;
}

bool int_stack_is_full(IntStack* s) {
    return s->top == INT_STACK_MAX - 1;
}

void int_stack_push(IntStack* s, int value) {
    if (int_stack_is_full(s)) {
        printf("IntStack overflow\n");
        exit(EXIT_FAILURE);
    }

    s->stack[++(s->top)] = value;
}

int int_stack_pop(IntStack* s) {
    if (int_stack_is_empty(s)) {
        printf("IntStack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[(s->top)--];
}

int int_stack_peek(IntStack* s) {
    if (int_stack_is_empty(s)) {
        printf("IntStack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top];
}
