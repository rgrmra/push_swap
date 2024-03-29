/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:08:03 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/27 19:06:12 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate_node(t_lnode **node)
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

void	rotate(t_stacks **stacks, int flag)
{
	if ((flag == STACK_A && !(*stacks)->a)
		|| (flag == STACK_B && !(*stacks)->b))
		return ;
	if (flag == STACK_A || flag == STACKS)
		rotate_node(&(*stacks)->a);
	if (flag == STACK_B || flag == STACKS)
		rotate_node(&(*stacks)->b);
}
