/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_three_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:31:04 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/27 19:33:09 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_top(t_stacks **stacks, int max)
{
	if ((*stacks)->a->next->nbr == max)
	{
		rotate(stacks, STACK_A, 1);
		swap(stacks, STACK_A);
		reverse(stacks, STACK_A, 1);
	}
}

static void	min_middle(t_stacks **stacks, int max)
{
	swap(stacks, STACK_A);
	if ((*stacks)->a->next->nbr == max)
	{
		rotate(stacks, STACK_A, 1);
		swap(stacks, STACK_A);
		reverse(stacks, STACK_A, 1);
	}
}

static void	min_bottom(t_stacks **stacks, int max)
{
	if ((*stacks)->a->nbr == max)
		swap(stacks, STACK_A);
	rotate(stacks, STACK_A, 1);
	swap(stacks, STACK_A);
	reverse(stacks, STACK_A, 1);
	swap(stacks, STACK_A);
}

void	three_handler_a(t_stacks **stacks)
{
	int		min;
	int		max;

	min = smaller((*stacks)->a, 3);
	max = bigger((*stacks)->a, 3);
	if ((*stacks)->size_a == 3)
		sort_three(stacks);
	else if ((*stacks)->a->nbr == min)
		min_top(stacks, max);
	else if ((*stacks)->a->next->nbr == min)
		min_middle(stacks, max);
	else if ((*stacks)->a->next->next->nbr == min)
		min_bottom(stacks, max);
}
