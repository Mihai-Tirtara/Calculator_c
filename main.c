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
    int result;
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
    // Placeholder for infix to postfix conversion logic
    return NULL;
}

int evaluate_postfix(const char* postfix) {
    // Placeholder for postfix evaluation logic
    return 0;
}



