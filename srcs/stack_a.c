/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:00:34 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/21 15:51:08 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exceptions(t_stacks **stacks, int size, int flag)
{
	if (size > 10)
		return (1);
	else if (size == 10)
		sort_ten_handler(stacks, flag);
	else if (size == 9)
		sort_nine_handler(stacks, flag);
	else if (size == 8)
		sort_eight_handler(stacks, flag);
	else if (size == 7)
		sort_seven_handler(stacks, flag);
	else if (size == 6)
		sort_six_handler(stacks, flag);
	else if (size == 5)
		sort_five_handler(stacks, flag);
	else if (size == 4)
		sort_four_handler(stacks, flag);
	else if (size == 3 && flag == STACK_A)
		three_handler_a(size, stacks);
	else if (size == 3)
		three_handler_b(size, stacks);
	else if (size == 2)
		two_handler(stacks, flag);
	else if (size == 1 && flag == STACK_B)
		push(stacks, STACK_A, 1);
	return (0);
}

static void	divide_stack_a(t_stacks **stacks, t_counters *counters, int *times)
{
	if (*times > 1 && (*stacks)->a->nbr < counters->big
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
	int			times;
	t_counters	counters;

	if (!exceptions(stacks, size, STACK_A))
		return ;
	init_counters((*stacks)->a, &counters, size);
	times = size;
	while (times--)
		divide_stack_a(stacks, &counters, &times);
	restore_stack_a(stacks, &counters, count);
	stack_a(counters.ra, stacks, count);
	stack_b(counters.rb, stacks, count);
	stack_b(counters.pb - counters.rb, stacks, count);
}