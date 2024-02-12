/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:00:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/11 22:28:34 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exceptions(t_stacks **stacks, int size)
{
	if (size > 5 || size == 4)
		return (1);
	else if (size == 5)
		sort_five_handler(size, stacks, STACK_B);
	else
		under_three_handler(size, stacks, STACK_B);
	return (0);
}

static void	push_rotate_b(t_stacks **stacks, t_counters *counters)
{
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

static void	back_to_orig_ra(t_stacks **stacks, t_counters *counters)
{
	int trrr;
	int	trra;

	trrr = counters->rb;
	trra = counters->ra - trrr;
	///while (trrr--)
	//	reverse(stacks, STACKS, 1);
	reverse(stacks, STACKS, trrr);
	//while (trra--)
	//	reverse(stacks, STACK_A, 1);
	reverse(stacks, STACK_A, trra);
}

static void	back_to_orig_rb(t_stacks **stacks, t_counters *counters)
{
	int trrr;
	int	trrb;

	trrr = counters->ra;
	trrb = counters->rb - trrr;
	//while (trrr--)
	//	reverse(stacks, STACKS, 1);
		reverse(stacks, STACKS, trrr);
	//while (trrb--)
	//	reverse(stacks, STACK_B, 1);
		reverse(stacks, STACK_B, trrb);
}

void	stack_b(int size, t_stacks **stacks, int *count)
{
	int			tmp;
	t_counters	counters;

	(*count)++;
	if (!exceptions(stacks, size))
		return ;
	init_counters(&counters);
	set_pivots((*stacks)->b, &counters, size);
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
