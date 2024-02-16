/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:00:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/14 21:03:10 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_stack_b(t_stacks **stacks, t_counters *counters, int *times)
{
	if (*times > 1 && (*stacks)->b->nbr >= counters->small
		&& (*stacks)->b->next->nbr <= counters->small
		&& (*stacks)->b->nbr <= counters->big)
	{
		push(stacks, STACK_A, 1);
		counters->pa++;
		rotate(stacks, STACKS, 1);
		counters->ra++;
		counters->rb++;
		(*times)--;
		return ;
	}
	if ((*stacks)->b->nbr <= counters->small)
	{
		rotate(stacks, STACK_B, 1);
		counters->rb++;
		return ;
	}
	push(stacks, STACK_A, 1);
	counters->pa++;
	if ((*stacks)->a->nbr <= counters->big)
	{
		rotate(stacks, STACK_A, 1);
		counters->ra++;
	}
}

static void	restore_stack_b(t_stacks **stacks, t_counters *counters)
{
	int	rrr;
	int	rrx;

	if (counters->ra > counters->rb)
	{
		rrr = counters->rb;
		rrx = counters->ra - rrr;
		reverse(stacks, STACK_A, rrx);
	}
	else
	{
		rrr = counters->ra;
		rrx = counters->rb - rrr;
		reverse(stacks, STACK_B, rrx);
	}
	reverse(stacks, STACKS, rrr);
}

void	stack_b(int size, t_stacks **stacks, int *count)
{
	int			times;
	t_counters	counters;

	(*count)++;
	if (!exceptions(stacks, size, STACK_B))
		return ;
	init_counters((*stacks)->b, &counters, size);
	times = size;
	while (times--)
		divide_stack_b(stacks, &counters, &times);
	stack_a(counters.pa - counters.ra, stacks, count);
	restore_stack_b(stacks, &counters);
	stack_a(counters.ra, stacks, count);
	stack_b(counters.rb, stacks, count);
}
