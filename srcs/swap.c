/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:00:16 by rde-mour          #+#    #+#             */
/*   Updated: 2024/03/14 21:30:53 by rde-mour         ###   ########.org.br   */
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

void	swap(t_stacks **stacks, int flag)
{
	if ((flag == STACK_A && (*stacks)->size_a < 2)
		|| (flag == STACK_B && (*stacks)->size_b < 2))
		return ;
	if (flag == STACK_A && (*stacks)->size_b > 1
		&& (*stacks)->b->nbr < (*stacks)->b->next->nbr)
		flag = STACKS;
	else if (flag == STACK_B && (*stacks)->size_a > 1
		&& (*stacks)->a->nbr > (*stacks)->a->next->nbr)
		flag = STACKS;
	if (flag == STACK_A || flag == STACKS)
		swap_node(&(*stacks)->a);
	if (flag == STACK_B || flag == STACKS)
		swap_node(&(*stacks)->b);
	if (flag == STACK_A)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (flag == STACK_B)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (flag == STACKS)
		ft_putendl_fd("ss", STDOUT_FILENO);
}
