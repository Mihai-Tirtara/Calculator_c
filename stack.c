#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void stack_init(Stack* s) {
    s->top = -1;
}

bool stack_is_empty(Stack* s) {
    return s->top == -1;
}

bool stack_is_full(Stack* s) {
    return s->top == MAX - 1;
}

void stack_push(Stack* s, char c) {
    if (stack_is_full(s)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    s->stack[++(s->top)] = c;
}

char stack_pop(Stack* s) {
    if (stack_is_empty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[(s->top)--];
}

char stack_peek(Stack* s) {
    if (stack_is_empty(s)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top];
}
