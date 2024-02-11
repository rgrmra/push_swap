/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:00:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/11 20:28:58 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exceptions(t_stacks **stacks, int size)
{
	if (size > 5 || size == 4)
		return (1);
	else if (size == 5)
		sort_five_handler(size, stacks, STACK_A);
	else 
		under_three_handler(size, stacks, STACK_A);
	return (0);
}

static void	push_rotate_a(t_stacks **stacks, t_counters *counters)
{
	if ((*stacks)->a->nbr > counters->big)
	{
		rotate(stacks, STACK_A, 1);
		counters->ra++;
	}
	else
	{
		push(stacks, STACK_B, 1);
		counters->pb++;
		if ((*stacks)->b->nbr > counters->small)
		{
			rotate(stacks, STACK_B, 1);
			counters->rb++;
		}
	}
}

static void	back_to_orig_ra(t_stacks **stacks, t_counters *counters, int *count)
{
	int trrr;
	int	trra;

	trrr = counters->rb;
	trra = counters->ra - trrr;
	if ((*count) > 0)
	{
		reverse(stacks, STACKS, trrr);
		reverse(stacks, STACK_A, trra);
	}
	else 
		reverse(stacks, STACK_B, trrr);
}

static void	back_to_orig_rb(t_stacks **stacks, t_counters *counters, int *count)
{
	int trrr;
	int	trrb;

	trrr = counters->ra;
	trrb = counters->rb - trrr;
	if ((*count) > 0)
	{
		reverse(stacks, STACKS, trrr);
		reverse(stacks, STACK_B, trrb);
	}
	else
		reverse(stacks, STACK_B, counters->rb);
}

void	stack_a(int size, t_stacks **stacks, int *count)
{
	int			tmp;
	t_counters	counters;

	if (!exceptions(stacks, size))
		return ;
	init_counters(&counters);
	set_pivots((*stacks)->a, &counters, size);
	tmp = size;
	while (tmp--)
		push_rotate_a(stacks, &counters);
	if (counters.ra > counters.rb)
		back_to_orig_ra(stacks, &counters, count);
	else
		back_to_orig_rb(stacks, &counters, count);
	stack_a(counters.ra, stacks, count);
	stack_b(counters.rb, stacks, count);
	stack_b(counters.pb - counters.rb, stacks, count);
}
