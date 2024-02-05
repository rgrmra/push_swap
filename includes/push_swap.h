/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:42:26 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/04 20:30:33 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_lnode	t_lnode;
struct s_lnode
{
	int		nbr;
	t_lnode	*next;
	t_lnode	*prev;
};

typedef struct s_stacks	t_stacks;
struct s_stacks
{
	t_lnode	*a;
	size_t	sa;
	t_lnode	*b;
	size_t	sb;
	int		min;
	int		max;
};

enum e_moves
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	NIL
};

enum e_order
{
	ASC,
	DESC
};

void	clear_stacks(t_stacks **stacks);
void	ft_error(t_stacks **stacks);
void	llstadd_back(t_lnode **stack, t_lnode *new);
void	llstadd_front(t_lnode **stack, t_lnode *new);
void	llstclear(t_lnode **stack);
t_lnode	*llstlast(t_lnode *stack);
t_lnode	*llstnew(int nbr);
size_t	llstsize(t_lnode *stack);
void	sa(t_stacks **stacks);
void	sb(t_stacks **stacks);
void	ss(t_stacks **stacks);
void	pa(t_stacks **stacks);
void	pb(t_stacks **stacks);
void	ra(t_stacks **stacks);
void	rb(t_stacks **stacks);
void	rr(t_stacks **stacks);
void	rra(t_stacks **stacks);
void	rrb(t_stacks **stacks);
void	rrr(t_stacks **stacks);

#endif