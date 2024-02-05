/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:24:40 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/03 16:01:19 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_lnode	**node)
{
	t_lnode	*last;

	if (!node || !(*node) || !(*node)->next)
		return ;
	last = llstlast(*node);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *node;
	(*node)->prev = last;
	(*node) = last;
}

void	rra(t_stacks **stacks)
{
	reverse(&(*stacks)->a);
	ft_printf("rra\n");
}

void	rrb(t_stacks **stacks)
{
	reverse(&(*stacks)->b);
	ft_printf("rrb\n");
}

void	rrr(t_stacks **stacks)
{
	reverse(&(*stacks)->a);
	reverse(&(*stacks)->b);
	ft_printf("rrr\n");
}
