<img align="center" src="https://royalbox.com.br/github/push_swap_banner.png">
<p align="center">
   <img src="https://img.shields.io/github/languages/code-size/rgrmra/push_swap?color=blue&style=for-the-badge" />
   <img src="https://img.shields.io/github/languages/top/rgrmra/push_swap?color=blue&style=for-the-badge" />
   <img src="https://img.shields.io/github/last-commit/rgrmra/push_swap?color=blue&style=for-the-badge" />
   <img src="https://img.shields.io/github/license/rgrmra/push_swap?color=blue&style=for-the-badge" />
</p>

# Push Swap Tester

> [!IMPORTANT]
> I moved **Push Swap Tester** to another git repository to keep here only the push_swap.<br>
> You could access it with the link bellow:
>
> Tester: [Push Swap Tester](https://github.com/rgrmra/push_swap_tester)

# Project

The project receives an amount of random numbers, store it in a stack and sort it in ascending order with a bunch of limited operations.

### Operations:

**sa (Swap A):** swap the first two elements at the top of stack A.<br>
Do nothing if there is only one or none elements.

**sb (Swap B):** swap the first two elements at the top of stack B.<br>
Do nothing if there is only one or none elements.

**ss (Swap A and B):** swap the first two elements at the top of stack A and B at the same time.<br>
Do nothing if there is only one or none elements.

**pa (Push A):** Take the first element at the top of stack B and put it at the top of stack A.<br>
Do nothing if stack B is empty.

**pb (Push B):** Take the first element at the top of stack A and put it at the top of stack B.<br>
Do nothing if stack A is empty.

**ra (Rotate A):** Shift up all elements of stack A by one.<br>
The first element becomes the last one.

**rb (Rotate B):** Shift up all elements of stack B by one.<br>
The first element becomes the last one.

**rr (Rotate A and B):** Shift up all elements of stack A and B by one at the same time by one.<br>
The first element of both stacks becomes the last one.

**rra (Reverse Rotate A):** Shift down all elements of stack A by one.<br>
The last element becomes the first one.

**rrb (Reverse Rotate B):** Shift down all elements of stack B by one.<br>
The last element becomes the first one.

**rrr (Reverse Rotate A and B):** Shift down all elements of stack A and B at the same time by one.<br>
The last element of both stacks becomes the last one.

<img align="center" src="https://royalbox.com.br/github/push_swap_moves.png">

### Algorithm:

This algorithm utilizes a Quicksort algorithm to sort the stack. But, insted of utilizing just only one pivot, it utilizes two pivots.

The problem is that we have some limitations of moves to do, and limit of operations that can be efficient to pass in the avaliation system.<br>
It's necessary to achieve to 700 moves with 100 numbers in the stack and 5500 moves with 500 numbers in the stack, the whole problem is that using just a simple Quicksort we have a range of moves between 700-800 moves with 100 numbers and 5000-6000 moves with 500 numbers.

So, insted of divide the stacks puting the largest numbers on one side and the smallest in the other side, it's better to divide the stack with 3 pivots; the big and the small pivot.

With this in mind, we can divide the stack in three pieces of numbers and utilizes recursion to do it again and again until the range of the stack achieve seven numbers. Then, we divide the stacks in two with only one pivot until the stack achieve three elements or less. With three elements or less, we can sort the stack, go to the previus recusion and do it until the stack is sorted.

<img align="center" src="https://royalbox.com.br/github/push_swap_quicksort.png">

> [!NOTE]
> In construction!

# How to use it?

Clone this repository:

```shell
git clone https://github.com/rgrmra/push_swap.git push_swap
```

Then compile the files as following:

#### Mandatory:

Sorts a quantity of numbers informed as parameters and prints the moves in the standard output.

```shell
make
```

#### Bonus:

Checks if the quantity of numbers could be sorted with expecified moves.

```shell
make bonus
```
