/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_three_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:31:04 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/11 20:55:39 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
	{
		if ((*stacks)->a->nbr > (*stacks)->a->next->nbr)
			swap(stacks, STACK_A);
	}
	else 
	{
		if ((*stacks)->b->nbr < (*stacks)->b->next->nbr)
			swap(stacks, STACK_B);
		push(stacks, STACK_A, 2);
	}
}

static void	three_top(t_stacks **stacks, int max)
{
	if ((*stacks)->size == 3)
	{
		if ((*stacks)->a->next->nbr == max)
		{
			reverse(stacks, STACK_A, 1);
			swap(stacks, STACK_A);
		}
	}
	else 
	{
		if ((*stacks)->a->next->nbr == max)
		{
			rotate(stacks, STACK_A, 1);
			swap(stacks, STACK_A);
			reverse(stacks, STACK_A, 1);
		}
	}
}

static void	three_middle(t_stacks **stacks, int max)
{
	if ((*stacks)->size == 3)
	{
		if ((*stacks)->a->next->next->nbr == max)
			swap(stacks, STACK_A);
		else
			rotate(stacks, STACK_A, 1);
	}
	else 
	{
		swap(stacks, STACK_A);
		if ((*stacks)->a->next->nbr == max)
		{
			rotate(stacks, STACK_A, 1);
			swap(stacks, STACK_A);
			reverse(stacks, STACK_A, 1);
		}
	}
}

static void	three_bottom(t_stacks **stacks, int max)
{
	if ((*stacks)->size == 3)
	{
		if ((*stacks)->a->nbr == max)
			swap(stacks, STACK_A);
		reverse(stacks, STACK_A, 1);
	}
	else 
	{
		if ((*stacks)->a->nbr == max)
			swap(stacks, STACK_A);
		rotate(stacks, STACK_A, 1);
		swap(stacks, STACK_A);
		reverse(stacks, STACK_A, 1);
		swap(stacks, STACK_A);
	}
}

void	three_handler_a(int size, t_stacks **stacks)
{
	int		min;
	int		max;

	min = smaller((*stacks)->a, size);
	max = bigger((*stacks)->a, size);
	if ((*stacks)->a->nbr == min)
		three_top(stacks, max);
	else if ((*stacks)->a->next->nbr == min)
		three_middle(stacks, max);
	else if ((*stacks)->a->next->next->nbr == min)
		three_bottom(stacks, max);
}

void	under_three_handler(int size, t_stacks **stacks, int flag)
{
	if (size == 3)
	{
		if (flag == STACK_A)
			three_handler_a(size, stacks);
		else
			three_handler_b(size, stacks);
	}
	else if (size == 2)
		two_handler(stacks, flag);
	else if (size == 1)
	{
		if (flag == STACK_B)
			push(stacks, STACK_A, 1);
	}
}
