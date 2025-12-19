#include <stdio.h>
#include <stdlib.h>

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
    char* input;
    char exit;
    char buff[1024];
    while (1) {
   printf("Enter calculation (or 'q' to quit): ");
    if (!fgets(buff, sizeof(buff), stdin)) {
        return 1;
    }
    if (buff[0] == 'q') {
        break;
    }
    printf("You entered: %s", buff);
    }

    return 0;

}



