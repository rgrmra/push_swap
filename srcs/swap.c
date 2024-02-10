/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:00:16 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/10 15:01:52 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_lnode **node)
{
	t_lnode	*first;

	if (!node || !(*node) || !(*node)->next)
		return ;
	first = *node;
	*node = (*node)->next;
	(*node)->prev = NULL;
	first->next = (*node)->next;
	(*node)->next = first;
	first->prev = *node;
	if (first->next)
		first->next->prev = first;
}

void	sa(t_stacks **stacks)
{
	swap(&(*stacks)->a);
	ft_printf("sa\n");
}

void	sb(t_stacks **stacks)
{
	swap(&(*stacks)->b);
	ft_printf("sb\n");
}

void	ss(t_stacks **stacks)
{
	swap(&(*stacks)->a);
	swap(&(*stacks)->b);
	ft_printf("ss\n");
}
