/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:24:40 by rde-mour          #+#    #+#             */
/*   Updated: 2024/03/14 21:33:35 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_node(t_lnode	**node)
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

void	reverse(t_stacks **stacks, int flags, int times)
{
	if (!times)
		return ;
	if ((flags == STACK_A && (*stacks)->a == 0)
		|| (flags == STACK_B && (*stacks)->b == 0))
		return ;
	if (flags == STACK_A || flags == STACKS)
		reverse_node(&(*stacks)->a);
	if (flags == STACK_B || flags == STACKS)
		reverse_node(&(*stacks)->b);
	if (flags == STACK_A)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (flags == STACK_B)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (flags == STACKS)
		ft_putendl_fd("rrr", STDOUT_FILENO);
	reverse(stacks, flags, --times);
}
