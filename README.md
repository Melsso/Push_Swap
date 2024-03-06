# Push Swap

Push Swap is a sorting algorithm project written in C. The goal is to organize a stack of integers in ascending order using a set of specific operations. The project consists of two stacks, named 'a' and 'b,' and the program, named `push_swap`, must output the minimal set of instructions to sort stack 'a'.

## Project Structure

The project should have the following files:

- **Makefile:** Compilation rules for the project.
- **\*.h:** Header files containing function prototypes.
- **\*.c:** Source code files containing the implementation of the sorting algorithm.

## Instructions

The available operations are as follows:

- **sa (swap a):** Swap the first 2 elements at the top of stack a.
- **sb (swap b):** Swap the first 2 elements at the top of stack b.
- **ss:** sa and sb at the same time.
- **pa (push a):** Take the first element at the top of b and put it at the top of a.
- **pb (push b):** Take the first element at the top of a and put it at the top of b.
- **ra (rotate a):** Shift up all elements of stack a by 1.
- **rb (rotate b):** Shift up all elements of stack b by 1.
- **rr:** ra and rb at the same time.
- **rra (reverse rotate a):** Shift down all elements of stack a by 1.
- **rrb (reverse rotate b):** Shift down all elements of stack b by 1.
- **rrr:** rra and rrb at the same time.

## Example

To illustrate the effect of some instructions, consider the following example:

```plaintext
Init a and b:
2
1
3
6
5
8
_ _
a b
```
Execute sa:

```plaintext
Copy code
1
2
3
6
5
8
_ _
a b
```
Execute pb pb pb:

```plaintext
Copy code
6 3
5 2
8 1
_ _
a b
```
## The "push_swap" Program

### Program Name: push_swap
### Turn in Files: Makefile, \*.h, \*.c
### Makefile: NAME, all, clean, fclean, re
### Arguments: stack a - A list of integers
### External Functions: read, write, malloc, free, exit, ft_printf, and any equivalent YOU coded
### Libft Authorized: Yes
### Description: Sort Stacks

The `push_swap` program takes, as an argument, the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).

The program must display the smallest list of instructions possible to sort the stack a, with the smallest number being at the top. Instructions must be separated by a '\n' and nothing else.

The goal is to sort the stack with the lowest possible number of operations.

If no parameters are specified, the program must not display anything and give the prompt back. In case of an error, it must display "Error" followed by a '\n' on the standard error. Errors include, for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.

My sorting algorithm uses the radix sort, so first we parse our input in order to simplfy it in order to improve Radix sort performance and also deal with negative numbers since the Radix sort does not work for negative numbers, so we map our numbers like this : consider the following list 3 -5 1 4, it will be mapped
as follows : -5 1 3 4 --> 0 1 2 3 --> 2 0 1 3, so essentially sorting the 2 1 0 3 sequence with the Radix sort will also sort our initial sequence that is 3 -5 1 4.
The Radix sort utilizes the bucket sorting algorithm logic, so we continuously sort numbers based on powers of 10 starting from the lowest to the highest power of ten, once we reach the highest our stack should be completely sorted.

### Usage Example

```bash
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```
```
$>./push_swap 0 one 2 3
Error
```
during the evaluation process, a binary called checker will be provided to properly check your program.

It will work as follows:
```
bash
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
```
If the program checker displays "KO," it means that your push_swap came up with a list of instructions that doesn’t sort the numbers. The checker program is available in the repository
