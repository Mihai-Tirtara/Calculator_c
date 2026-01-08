#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "queue.h"

char* infix_to_postfix(const char* infix);
int  evaluate_postfix(const char* postfix);


const char* welcome_message =
    "Welcome to a Simple Calculator\n"
    "================================\n\n"
    "This is a simple calculator implementation.\n"
    "It supports basic arithmetic operations:\n"
    "  +  (addition)\n"
    "  -  (subtraction)\n"
    "  *  (multiplication)\n"
    "  /  (division)\n\n"
    "To exit the program, type 'q'\n"; 



int main(void) {
    printf("%s", welcome_message);
    char* postfix;
    //int result;
    char buff[MAX];

    while (1) {
   printf("Enter calculation (or 'q' to quit): ");

    if (!fgets(buff, sizeof(buff), stdin)) {
        return 1;
    }

    if (buff[0] == 'q') {
        break;
    }

    else {
         postfix = infix_to_postfix(buff);
        //result = evaluate_postfix(postfix);
        //return result;
        printf("This the expression in postfix %s \n", postfix);
    }

    return 0;
 }
}


char* infix_to_postfix(const char* infix) {
    Stack op_stack;
    Queue output_queue;
    stack_init(&op_stack);
    queue_init(&output_queue);

    for(int i = 0; infix[i]!='\0'; i++) {
        if (infix[i] == ' ' || infix[i] == '\n') {
            continue;
        }
        if(infix[i] >= '0' && infix[i] <= '9') {
            queue_enque(&output_queue, infix[i]);
        }
        else if(infix[i] == '+' || infix[i] == '-'|| infix[i] == '*' || infix[i] == '/') {
            if(stack_is_empty(&op_stack)){
                stack_push(&op_stack, infix[i]);
            }
            else {
                if(infix[i] == '*' && stack_peek(&op_stack) == '/') {
                    queue_enque(&output_queue, stack_pop(&op_stack));
                    stack_push(&op_stack, infix[i]);
                }
                else if(infix[i] == '/' && stack_peek(&op_stack) == '*') {
                    queue_enque(&output_queue, stack_pop(&op_stack));
                    stack_push(&op_stack, infix[i]);
                }
                else if(infix[i] == '+' && (stack_peek(&op_stack) == '*' || stack_peek(&op_stack) == '/')) {
                    queue_enque(&output_queue, stack_pop(&op_stack));
                    stack_push(&op_stack, infix[i]);
                }
                else if(infix[i] == '-' && (stack_peek(&op_stack) == '*' || stack_peek(&op_stack) == '/')) {
                    queue_enque(&output_queue, stack_pop(&op_stack));
                    stack_push(&op_stack, infix[i]);
                }
                else if(infix[i] == '+' && stack_peek(&op_stack) == '-') {
                    queue_enque(&output_queue, stack_pop(&op_stack));
                    stack_push(&op_stack, infix[i]);
                }
                else if(infix[i] == '-' && stack_peek(&op_stack) == '+') {
                    queue_enque(&output_queue, stack_pop(&op_stack));
                    stack_push(&op_stack, infix[i]);
                }
                else {
                    stack_push(&op_stack, infix[i]);
                }
            }

        }
        else if (infix[i] == '(') {
            stack_push(&op_stack, infix[i]);
        }
        else if (infix[i] == ')') {
            while(!stack_is_empty(&op_stack) && stack_peek(&op_stack) != '(') {
                queue_enque(&output_queue, stack_pop(&op_stack));
            }
            if(!stack_is_empty(&op_stack) && stack_peek(&op_stack) == '(') {
                stack_pop(&op_stack);
            }
        }
    }


    return queue_to_string(&output_queue);
}

int evaluate_postfix(const char* postfix) {
    // Placeholder for postfix evaluation logic
    return 0;
}



