# Stack_solver
Stack solving program in C

Given a set of ints, efficiently sorts the data using two stacks and a limited number of operations.

* The game is composed of 2 stacks named a and b.
* To start with:
* a contains a random number of either positive or negative numbers without any duplicates.
* b is empty
* The goal is to sort in ascending order numbers into stack a.
* To do this you have the following operations at your disposal:
  * sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
  * sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
  * ss : sa and sb at the same time.
  * pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  * pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  * ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
  * rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
  * rr : ra and rb at the same time.
  * rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

My program uses three different sorts:
* An insertion sort for data sets with more than 10 elements.
* A bubble sort for data sets between 3 and 10.
* A simple sort which only uses SA, RA and RRA.

Example usage:

    git clone https://github.com/tpan/stack_solver.git
    make
    
    $ ./push_swap 42 10 20 6 3
    sa rra pb rra pb pb ra pa pa pa
    
For 100 random ints, less than 700 operations should be required.
For 500 random ints, fewer than 5300 operations.

I also included a verbose '-v' flag which serves as a visualizer for the stacks.
    ./push_Swap 42 10 20 6 3 -v

* Of course, it must conform to the [42 Norm style guide](https://github.com/tpan/stack_solver/blob/master/push_swap.en.pdf)

Authorized functions
* write
* malloc
* free
* exit
