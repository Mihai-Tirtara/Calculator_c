How to create a calculator

Creating a simple calculator can be done using various programming languages. Below is an example of how to create a basic calculator using C.

General Requirements:
It should be a terminal based application that can perform addition, subtraction, multiplication, and division.
The user wil type the operation, press enter and get the result
The computer will return then result and wait for the next operation
The use can type "q" to exit the program

Supported operations:
1. Addition (+)
2. Subtraction (-)
3. Multiplication (*)
4. Division (/)
   Parentheses can be used for operations order.

Error  handling:
1. Division by zero should be handled gracefully with an error message.
2. Letters instead of numbers should be handled with and error message.
3. Only use whole numbers no floats.


Program Structure:

- Method to display welcome message and instructions
- while main loop that run until the user press q and q is the only element in the input.
- Method to parse the input and put it on the stack
- Method to parse the digits from string to integer looping through an array of characters and returning the int
- Method to do the calculation

Eror that could happen:
IF the user inputs the letter q inside an operation could that trigger the program to exit?

Questions to consider:
How do we parse the user input ? is everything they send an array of characters ?
What do we do when they have a 10 digits number ? I guess the easiest way is to parse the input as a string and then go through each digit and at the end return the int
What do we do with the operators ?
I know we should use a stack but I'm not entirely certain how.
Okay, I think I figured out, I've been looking at the stack from a wrong perspective, we shouldn't put stuff on the stack in this order:
Let's say we have "5+3", my first thought was to push(5), push(+), push(3) but that wouldn't work.
We should get the numbers first then the operands, we should something like this push(5), push(3), push(+), because stacks are last-in first out.
So we will pop() and we will get the operand, in this case +, so we know that the other two elements from the stack we would do an addition.
In the case we have a longer operation such as "5 + (2-1) + 7" we will have "5 2 1 - + 7 + "
We gonna use the reverse polish notation.
