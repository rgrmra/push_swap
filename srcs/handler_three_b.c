/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_three_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:31:04 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/27 19:34:39 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_top(t_stacks **stacks, int max)
{
	if ((*stacks)->size_b == 3)
	{
		rotate(stacks, STACK_B, 1);
		if ((*stacks)->b->next->nbr == max)
			swap(stacks, STACK_B);
	}
	else
	{
		swap(stacks, STACK_B);
		rotate(stacks, STACK_B, 1);
		swap(stacks, STACK_B);
		reverse(stacks, STACK_B, 1);
		if ((*stacks)->b->next->nbr == max)
			swap(stacks, STACK_B);
	}
}

static void	min_middle(t_stacks **stacks, int max)
{
	if ((*stacks)->size_b == 3)
	{
		reverse(stacks, STACK_B, 1);
		if ((*stacks)->b->next->nbr == max)
			swap(stacks, STACK_B);
	}
	else
	{
		rotate(stacks, STACK_B, 1);
		swap(stacks, STACK_B);
		reverse(stacks, STACK_B, 1);
		if ((*stacks)->b->next->nbr == max)
			swap(stacks, STACK_B);
	}
}

static void	min_bottom(t_stacks **stacks, int max)
{
	if ((*stacks)->b->next->nbr == max)
		swap(stacks, STACK_B);
}

void	three_handler_b(t_stacks **stacks)
{
	int		min;
	int		max;

	min = smaller((*stacks)->b, 3);
	max = bigger((*stacks)->b, 3);
	if ((*stacks)->b->nbr == min)
		min_top(stacks, max);
	else if ((*stacks)->b->next->nbr == min)
		min_middle(stacks, max);
	else if ((*stacks)->b->next->next->nbr == min)
		min_bottom(stacks, max);
	push(stacks, STACK_A, 3);
}
