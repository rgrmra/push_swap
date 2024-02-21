/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:58:38 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/21 13:01:12 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_a(t_stacks **stacks, int size)
{
	int	mid;
	int	pushs;
	int	rotates;

	pushs = (size / 2);
	rotates = 0;
	mid = middler((*stacks)->a, size);
	while (pushs)
	{
		if ((*stacks)->a->nbr < mid && pushs--)
		{
			push(stacks, STACK_B, 1);
			if ((*stacks)->a->next->nbr < mid)
				swap(stacks, STACK_A);
		}
		else if (++rotates)
			rotate(stacks, STACK_A, 1);
	}
	reverse(stacks, STACK_A, rotates);
}

static void	sort_stack_b(t_stacks **stacks, int size)
{
	int	mid;
	int	pushs;
	int	rotates;

	pushs = (size / 2) + (size % 2);
	rotates = 0;
	mid = middler((*stacks)->b, size);
	while (pushs)
	{
		if ((*stacks)->b->nbr >= mid && pushs--)
		{
			push(stacks, STACK_A, 1);
			if ((*stacks)->b->next->nbr >= mid)
				swap(stacks, STACK_B);
		}
		else if (++rotates)
			rotate(stacks, STACK_B, 1);
	}
	reverse(stacks, STACK_B, rotates);
}

void	sort_ten_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
		sort_stack_a(stacks, 10);
	else
		sort_stack_b(stacks, 10);
	sort_five_handler(stacks, STACK_A);
	sort_five_handler(stacks, STACK_B);
}

void	sort_nine_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
		sort_stack_a(stacks, 9);
	else
		sort_stack_b(stacks, 9);
	sort_five_handler(stacks, STACK_A);
	sort_four_handler(stacks, STACK_B);
}

void	sort_eight_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
		sort_stack_a(stacks, 8);
	else
		sort_stack_b(stacks, 8);
	sort_four_handler(stacks, STACK_A);
	sort_four_handler(stacks, STACK_B);
}

void	sort_seven_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
		sort_stack_a(stacks, 7);
	else
		sort_stack_b(stacks, 7);
	sort_four_handler(stacks, STACK_A);
	three_handler_b(3, stacks);
}

void	sort_six_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
		sort_stack_a(stacks, 6);
	else
		sort_stack_b(stacks, 6);
	three_handler_a(3, stacks);
	three_handler_b(3, stacks);
}

void	sort_four_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
		sort_stack_a(stacks, 4);
	else
		sort_stack_b(stacks, 4);
	two_handler(stacks, STACK_A);
	two_handler(stacks, STACK_B);
}

void	sort_five_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
		sort_stack_a(stacks, 5);
	else
		sort_stack_b(stacks, 5);
	three_handler_a(3, stacks);
	two_handler(stacks, STACK_B);
}

void	two_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_B)
	{
		if ((*stacks)->b->nbr < (*stacks)->b->next->nbr)
			swap(stacks, STACK_B);
		push(stacks, STACK_A, 2);
	}
	else if ((*stacks)->a->nbr > (*stacks)->a->next->nbr)
		swap(stacks, STACK_A);
}
