/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:00:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/10 15:15:05 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exceptions(t_stacks **stacks, int size)
{
	if (size <= 3)
	{
		sort_three(stacks);
		return (0);
	}
	else if (size == 5)
	{
		sort_five(stacks);
		return (0);
	}
	if (!stacks)
		return (0);
	return (1);
}
static void	push_rotate_b(t_stacks **stacks, t_counters *counters)
{
	if ((*stacks)->b->nbr > counters->small)
	{
		rb(stacks);
		counters->rb++;
		return ;
	}
	pa(stacks);
	counters->pa++;
	if ((*stacks)->a->nbr > counters->big)
	{
		ra(stacks);
		counters->ra++;
	}
}

static void	back_to_orig_ra(t_stacks **stacks, t_counters *counters)
{
	int trrr;
	int	trra;

	trrr = counters->rb;
	trra = counters->ra - trrr;
	while (trrr--)
		rrr(stacks);
	while (trra--)
		rra(stacks);
}

static void	back_to_orig_rb(t_stacks **stacks, t_counters *counters)
{
	int trrr;
	int	trrb;

	trrr = counters->ra;
	trrb = counters->rb - trrr;
	while (trrr--)
		rrr(stacks);
	while (trrb--)
		rrb(stacks);
}

void	stack_b(int size, t_stacks **stacks, int *count)
{
	int			tmp;
	t_counters	counters;

	(*count)++;
	if (!exceptions(stacks, size))
		return ;
	init_counters(&counters);
	set_pivots((*stacks)->a, &counters);
	tmp = size;
	while (tmp--)
		push_rotate_b(stacks, &counters);
	stack_a(counters.pa - counters.ra, stacks, count);
	if (counters.ra > counters.rb)
		back_to_orig_ra(stacks, &counters);
	else
		back_to_orig_rb(stacks, &counters);
	stack_a(counters.ra, stacks, count);
	stack_b(counters.rb, stacks, count);
}
