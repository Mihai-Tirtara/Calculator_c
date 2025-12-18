# Simple Calculator in C

A terminal-based calculator implementation in C that supports basic arithmetic operations with proper order of operations using parentheses.

## Features

### Supported Operations
- **Addition** (+)
- **Subtraction** (-)
- **Multiplication** (*)
- **Division** (/)
- **Parentheses** for operation precedence

### User Interface
- Terminal-based interactive application
- User types an operation and presses enter to get the result
- Program continuously accepts new operations until exit
- Type `q` to exit the program

### Error Handling
1. Division by zero is handled gracefully with an error message
2. Invalid input (letters instead of numbers) displays an error message
3. Only whole numbers are supported (no floats)

## How It Works

This calculator uses **Reverse Polish Notation (RPN)** and the **Shunting Yard Algorithm** to evaluate expressions.

### The Shunting Yard Algorithm

The algorithm works in two phases:

#### Phase 1: Infix to RPN Conversion

Uses two data structures:
- **Output queue** (or list) for the final RPN expression
- **Operator stack** for temporarily holding operators and parentheses

**Algorithm steps:**
1. Read tokens (numbers, operators, parentheses) left to right
2. **If number:** add it directly to output queue
3. **If operator:**
   - While there's an operator on top of the stack with higher or equal precedence, pop it to output
   - Then push your current operator onto the stack
4. **If left parenthesis `(`:** push it onto the stack
5. **If right parenthesis `)`:**
   - Pop operators to output until you find the matching `(`
   - Discard both parentheses
6. **At the end:** pop all remaining operators to output

**Example:** `5 + (2 - 1) * 7`

| Token | Stack      | Output Queue           |
|-------|------------|------------------------|
| 5     | []         | [5]                    |
| +     | [+]        | [5]                    |
| (     | [+, (]     | [5]                    |
| 2     | [+, (]     | [5, 2]                 |
| -     | [+, (, -]  | [5, 2]                 |
| 1     | [+, (, -]  | [5, 2, 1]              |
| )     | [+]        | [5, 2, 1, -]           |
| *     | [+, *]     | [5, 2, 1, -]           |
| 7     | [+, *]     | [5, 2, 1, -, 7]        |
| END   | []         | [5, 2, 1, -, 7, *, +]  |

#### Phase 2: Evaluate RPN

Uses a single stack:
1. Read RPN left to right
2. **Number?** Push it onto the stack
3. **Operator?** Pop two numbers, calculate, push result back

## Program Structure

- [x] Display welcome message and instructions
- [ ] Main while loop that runs until user enters `q` as the only input
- [ ] Method to parse input and return expression in infix notation
- [ ] Method to convert from infix to postfix (RPN)
- [ ] Method to evaluate postfix expression and return result

## Development Notes

### Design Decisions

**Input Parsing:**
- User input is treated as an array of characters
- Multi-digit numbers are parsed by iterating through consecutive digits and converting to an integer
- Operators are identified and handled separately

**Stack Usage:**
The key insight is understanding how stacks work with RPN:
- For `5+3`, we don't push in order: `push(5), push(+), push(3)`
- Instead, we convert to RPN first: `5 3 +`
- Then evaluate: `push(5), push(3), push(+)` where `+` triggers popping two operands and pushing the result
- For `5 + (2-1) + 7`, the RPN is: `5 2 1 - + 7 +`

### Known Considerations

**Potential Edge Cases:**
- What happens if the user inputs `q` inside an operation? (e.g., `5+q`)
  - Should only exit when `q` is the sole input element