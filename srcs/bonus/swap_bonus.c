/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:00:16 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/26 19:06:37 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	swap(t_stacks **stacks, int flag)
{
	if (flag == STACK_A || flag == STACKS)
		swap_node(&(*stacks)->a);
	if (flag == STACK_B || flag == STACKS)
		swap_node(&(*stacks)->b);
}
