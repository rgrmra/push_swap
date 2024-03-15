/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:08:03 by rde-mour          #+#    #+#             */
/*   Updated: 2024/03/14 21:33:21 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rotate(t_stacks **stacks, int flag, int times)
{
	if (!times)
		return ;
	if ((flag == STACK_A && (*stacks)->size_a == 0)
		|| (flag == STACK_B && (*stacks)->size_b == 0))
		return ;
	if (flag == STACK_A || flag == STACKS)
		rotate_node(&(*stacks)->a);
	if (flag == STACK_B || flag == STACKS)
		rotate_node(&(*stacks)->b);
	if (flag == STACK_A)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (flag == STACK_B)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (flag == STACKS)
		ft_putendl_fd("rr", STDOUT_FILENO);
	rotate(stacks, flag, --times);
}
