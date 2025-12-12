_This project has been created as part
of the 42 curriculum by abisiani_

# push_swap
Because swap_push doesn't feel as natural

<br>

## Description

*push_swap* physically sorts a "stack" of **unique** integers in ascending order using a limited operation set and two circular lists. *push_swap*  The goal is to minimise the number of operations necessary in the general case, while staying within:
* For n = 100 under 1100 operations and for n = 500 in under 8500 operations.
* For n = 100 under 700 operations and for n = 500 numbers in under 11500 operations.
* For n = 100 under 1300 operations and for n = 500 numbers in under 5500 operations.

Target efficiency is:
* For n = 100: 700 or fewer operations.
* For n = 500: 5500 or fewer operations.

The operations available for use are:
* **sa** (swap a): **Swap** the first 2 elements at the top of stack a. Do nothing if there is only one element or none.
* **sb** (swap b): **Swap** the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
* **ss** : sa and sb at the same time.
* **pa** (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* **pb** (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* **ra** (rotate a): **Shift up** all elements of stack a by 1. The first element becomes the last one.
* **rb** (rotate b): **Shift up** all elements of stack b by 1. The first element becomes the last one.
* **rr** : ra and rb at the same time.
* **rra** (reverse rotate a): **Shift down** all elements of stack a by 1. The last element becomes the first one.
* **rrb** (reverse rotate b): **Shift down** all elements of stack b by 1. The last element becomes the first one.
* **rrr** : rra and rrb at the same time.

<br>

### Current efficiency averages for n:
![image](efficiency_scatter_1.png)

## Instructions

Build *push_swap* with `make`.

Run it by passing the elements of the list on the command line:

	./push_swap 5 4 7 3 8 0

It will output the operations it took (and any errors) to stdout:

	./push_swap 5 4 7 3 8 0
	pb
	pb
	ra
	pb
	rr
	pb
	etc..


## Resources

AI was used to 
* Calculate projected operations costs of possible algorithms.
* Repeat test setup and teardown pattern for given test cases.
* Generate files containing test inputs.
* Generating plot_results.py (using matplotlib to view results).

Classic tutorials and resources on this challenge that however do not relate to the algorithm used here:
* [Mechanical turk algo (Medium.com)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
* [The least amount of moves with two stacks - Jamie Dawson (Medium.com)](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
