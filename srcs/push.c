/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:28:08 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/04 20:36:43 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_lnode **orig, t_lnode **dest)
{
	t_lnode	*node;

	if (!orig || !(*orig))
		return ;
	node = *orig;
	*orig = (*orig)->next;
	if (*orig)
		(*orig)->prev = NULL;
	node->next = *dest;
	if (*dest)
		(*dest)->prev = node;
	node->prev = NULL;
	*dest = node;
}

void	pa(t_stacks **stacks)
{
	push(&(*stacks)->b, &(*stacks)->a);
	(*stacks)->sa++;
	(*stacks)->sb--;
	ft_printf("pa\n");
}

void	pb(t_stacks **stacks)
{
	push(&(*stacks)->a, &(*stacks)->b);
	(*stacks)->sa--;
	(*stacks)->sb++;
	ft_printf("pb\n");
}
