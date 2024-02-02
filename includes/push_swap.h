/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:42:26 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/02 18:27:54 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_psnode	t_psnode;
struct s_psnode
{
	int		nbr;
	t_psnode	*next;
	t_psnode	*prev;
};

typedef struct s_stacks	t_stacks;
struct s_stacks
{
	t_psnode	*a;
	t_psnode	*b;
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
	RRR
};

t_psnode	*ps_lstnew(int nbr);
t_psnode	*ps_lstlast(t_psnode *stack);
void		ps_lstadd_front(t_psnode **stack, t_psnode *new);
void		ps_lstadd_back(t_psnode **stack, t_psnode *new);
void		ps_lstclear(t_psnode **stack);

#endif
