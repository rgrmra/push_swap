/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:42:26 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/27 19:48:16 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define PS_MIN -2147483648
# define PS_MAX	+2147483647
# define HANDLER_LIMITER 8

typedef struct s_lnode		t_lnode;
struct s_lnode
{
	int		nbr;
	t_lnode	*next;
	t_lnode	*prev;
};

typedef struct s_stacks		t_stacks;
struct s_stacks
{
	t_lnode	*a;
	t_lnode	*b;
};

enum e_flags
{
	STACK_A,
	STACK_B,
	STACKS
};

enum e_errors
{
	FAILURE,
	SUCCESS
};

void	stack_a(int size, t_stacks **stacks, int *count);
void	stack_b(int size, t_stacks **stacks, int *count);

void	check_sorting(t_stacks **stacks);
int		sorter(t_stacks **stacks, char *move);

void	clear_stacks(t_stacks **stacks);
void	ft_error(t_stacks **stacks);
void	llstadd_back(t_lnode **stack, t_lnode *new);
t_lnode	*llstlast(t_lnode *stack);
t_lnode	*llstnew(int nbr);

void	swap(t_stacks **stacks, int moves);
void	rotate(t_stacks **stacks, int moves);
void	push(t_stacks **stacks, int moves);
void	reverse(t_stacks **stacks, int moves);

#endif
