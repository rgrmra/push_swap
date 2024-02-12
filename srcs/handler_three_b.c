/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_three_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:31:04 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/11 21:10:10 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_top(t_stacks **stacks, int max)
{
	if (llstsize((*stacks)->b) == 3)
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

static void	three_middle(t_stacks **stacks, int max)
{
	if (llstsize((*stacks)->b) == 3)
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

static void	three_bottom(t_stacks **stacks, int max)
{
	if ((*stacks)->b->next->nbr == max)
		swap(stacks, STACK_B);
}

void	three_handler_b(int size, t_stacks **stacks)
{
	int		min;
	int		max;

	min = smaller((*stacks)->b, size);
	max = bigger((*stacks)->b, size);
	if ((*stacks)->b->nbr == min)
		three_top(stacks, max);
	else if ((*stacks)->b->next->nbr == min)
		three_middle(stacks, max);
	else if ((*stacks)->b->next->next->nbr == min)
		three_bottom(stacks, max);
	push(stacks, STACK_A, 3);
}
