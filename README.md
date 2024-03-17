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

### Algorithm

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
