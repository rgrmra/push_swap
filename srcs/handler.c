/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:58:38 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/27 19:37:25 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_sorted(t_lnode *stack, int flag, int size)
{
	t_lnode	*node;

	node = stack;
	while (node && --size)
	{
		if (flag == STACK_A && node->next && node->nbr > node->next->nbr)
			return (FAILURE);
		else if (node->next && node->nbr < node->next->nbr)
			return (FAILURE);
		node = node->next;
	}
	return (SUCCESS);
}

static void	sort_stack_a(t_stacks **stacks, int size)
{
	int	mid;
	int	pushs;
	int	rotates;

	pushs = (size / 2);
	rotates = 0;
	mid = middler((*stacks)->a, pushs + (size % 2), size);
	while (pushs)
	{
		if ((*stacks)->a->nbr < mid && pushs--)
			push(stacks, STACK_B, 1);
		else
		{
			rotate(stacks, STACK_A, 1);
			rotates++;
		}
	}
	if ((*stacks)->size_a > rotates)
		reverse(stacks, STACK_A, rotates);
}

static void	sort_stack_b(t_stacks **stacks, int size)
{
	int	mid;
	int	pushs;
	int	rotates;

	pushs = (size / 2) + (size % 2);
	rotates = 0;
	mid = middler((*stacks)->b, pushs, size);
	while (pushs)
	{
		if ((*stacks)->b->nbr >= mid && pushs--)
			push(stacks, STACK_A, 1);
		else
		{
			rotate(stacks, STACK_B, 1);
			rotates++;
		}
	}
	if ((*stacks)->size_b > rotates)
		reverse(stacks, STACK_B, rotates);
}

static int	check_handler(t_stacks **stacks, int flag, int size)
{
	if (size > 3)
		return (FAILURE);
	else if (size == 3 && flag == STACK_A)
		three_handler_a(stacks);
	else if (size == 3)
		three_handler_b(stacks);
	else if (size == 2 && flag == STACK_B)
	{
		if ((*stacks)->b->nbr < (*stacks)->b->next->nbr)
			swap(stacks, STACK_B);
		push(stacks, STACK_A, 2);
	}
	else if (size == 2)
	{
		if ((*stacks)->a->nbr > (*stacks)->a->next->nbr)
			swap(stacks, STACK_A);
	}
	else if (size == 1 && flag == STACK_B)
		push(stacks, STACK_A, 1);
	return (SUCCESS);
}

void	sort_handler(t_stacks **stacks, int flag, int size)
{
	if (check_handler(stacks, flag, size))
		return ;
	if (flag == STACK_A)
	{
		if (!stack_sorted((*stacks)->a, flag, size))
			sort_stack_a(stacks, size);
		else
			return ;
	}
	else
	{
		if (!stack_sorted((*stacks)->b, flag, size))
			sort_stack_b(stacks, size);
		else
		{
			push(stacks, STACK_A, size);
			return ;
		}
	}
	sort_handler(stacks, STACK_A, (size / 2) + (size % 2));
	sort_handler(stacks, STACK_B, (size / 2));
}
