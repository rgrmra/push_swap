/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:00:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/23 14:08:35 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_stack_a(t_stacks **stacks, t_counters *counters, int *times)
{
	if (*times && (*stacks)->a->nbr < counters->big
		&& (*stacks)->a->next->nbr > counters->big
		&& (*stacks)->a->nbr > counters->small)
	{
		push(stacks, STACK_B, 1);
		counters->pb++;
		rotate(stacks, STACKS, 1);
		counters->ra++;
		counters->rb++;
		(*times)--;
		return ;
	}
	if ((*stacks)->a->nbr > counters->big)
	{
		rotate(stacks, STACK_A, 1);
		counters->ra++;
		return ;
	}
	push(stacks, STACK_B, 1);
	counters->pb++;
	if ((*stacks)->b->nbr > counters->small)
	{
		rotate(stacks, STACK_B, 1);
		counters->rb++;
	}
}

static void	restore_stack_a(t_stacks **stacks, t_counters *counters, int *count)
{
	int	rrr;
	int	rrx;

	if (counters->ra > counters->rb)
	{
		rrr = counters->rb;
		rrx = counters->ra - rrr;
		if ((*count) > 0)
			reverse(stacks, STACK_A, rrx);
		else
			reverse(stacks, STACK_B, rrr);
	}
	else
	{
		rrr = counters->ra;
		rrx = counters->rb - rrr;
		if ((*count) > 0)
			reverse(stacks, STACK_B, rrx);
		else
			reverse(stacks, STACK_B, counters->rb);
	}
	if ((*count) > 0)
		reverse(stacks, STACKS, rrr);
}

void	stack_a(int size, t_stacks **stacks, int *count)
{
	t_counters	counters;

	if (size < HANDLER_LIMITER)
	{
		sort_handler(stacks, STACK_A, size);
		return ;
	}
	init_counters((*stacks)->a, &counters, size);
	while (size--)
		divide_stack_a(stacks, &counters, &size);
	restore_stack_a(stacks, &counters, count);
	stack_a(counters.ra, stacks, count);
	stack_b(counters.rb, stacks, count);
	stack_b(counters.pb - counters.rb, stacks, count);
}
