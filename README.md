##  push_swap

    * 42 project: Sort a stack of integers with a limited set of operations, using the least number of moves.


## Project Description

The goal of push_swap is to sort a stack of integers using a restricted set of operations, as efficiently as possible.
You must develop a program that outputs the list of instructions needed to sort the stack.
The fewer instructions, the better!

Additionally, a bonus program checker must be created to verify if a sequence of operations correctly sorts a given stack.

## How it works

    You are given two stacks:

            - A: Initially contains all the integers (unsorted).

            - B: Starts empty.

You can only use the following operations:

        Operation    | Description  
        
        sa           | Swap the first two elements of A  
        sb           | Swap the first two elements of B  
        ss           | sa and sb at the same time  
        pa           | Push the top element of B onto A  
        pb           | Push the top element of A onto B  
        ra           | Rotate A upwards  
        rb           | Rotate B upwards  
        rr           | ra and rb at the same time  
        rra          | Rotate A downwards (reverse)  
        rrb          | Rotate B downwards (reverse)  
        rrr          | rra and rrb at the same time  


##  Objectives


    - Parse and validate input arguments.

    - Detect duplicate numbers.

    - Sort stacks efficiently with as few operations as possible.

    - Handle stacks of various sizes, especially edge cases like 2-3 elements.

    - For bonus: Implement a checker program that validates a given sequence of operations.


## How to use

1. Compile: 

            make
    for bonus:

            make bonus

2. Run push_swap

        ./push_swap [numbers...]

3. Run checker (bonus)

        ./checker [numbers...]