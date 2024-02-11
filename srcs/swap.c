/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:00:16 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/10 15:51:52 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_node(t_lnode **node)
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

void	swap(t_stacks **stacks, int moves)
{
	if (moves == STACK_A || moves == STACKS)
		swap_node(&(*stacks)->a);
	if (moves == STACK_B || moves == STACKS)
		swap_node(&(*stacks)->b);
	if (moves == STACK_A)
		ft_printf("sa\n");
	else if (moves == STACK_B)
		ft_printf("sb\n");
	else if (moves == STACKS)
		ft_printf("ss\n");
}
