/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:08:03 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/03 20:10:35 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_lnode **node)
{
	t_lnode	*last;

	if (!node || !(*node) || !(*node)->next)
		return ;
	last = llstlast(*node);
	last->next = *node;
	*node = (*node)->next;
	(*node)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stacks	**stacks)
{
	rotate(&(*stacks)->a);
	ft_printf("ra\n");
}

void	rb(t_stacks	**stacks)
{
	rotate(&(*stacks)->b);
	ft_printf("rb\n");
}

void	rr(t_stacks	**stacks)
{
	rotate(&(*stacks)->a);
	rotate(&(*stacks)->b);
	ft_printf("rr\n");
}
