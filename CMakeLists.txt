cmake_minimum_required(VERSION 3.10)

project(Calculator C)

set(CMAKE_C_STANDARD 11)

add_executable(calculator
    main.c
    stack.c
    queue.c
    int_stack.c
)
