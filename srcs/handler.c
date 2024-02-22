/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:58:38 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/22 16:01:56 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sorting_a(t_lnode *stack, int size)
{
	t_lnode	*node;

	node = stack;
	while (node && --size)
	{
		if (node->next && node->nbr > node->next->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

static int	check_sorting_b(t_lnode *stack, int size)
{
	t_lnode	*node;

	node = stack;
	while (node && --size)
	{
		if (node->next && node->nbr < node->next->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

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

int	handler(t_stacks **stacks, int flag, int size)
{
	if (size > 3)
		return (1);
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

void	sort_handler(t_stacks **stacks, int flag, int size)
{
	if (!handler(stacks, flag, size))
		return ;
	if (flag == STACK_A)
	{
		if (!check_sorting_a((*stacks)->a, size))
			sort_stack_a(stacks, size);
		else
			return ;
	}
	else 
	{
		if (!check_sorting_b((*stacks)->b, size))
			sort_stack_b(stacks, size);
		else
		{
			push(stacks, STACK_A, size);
			return ;
		}
	}
	sort_handler(stacks, STACK_A, (size / 2) + (size % 2));
	sort_handler(stacks, STACK_B, size / 2);
	push(stacks, STACK_A, size / 2);
}

void	sort_ten_handler(t_stacks **stacks, int flag)
{
	sort_handler(stacks, STACK_A, 10);
	/*
	if (flag == STACK_A)
	{
		if (!check_sorting_a((*stacks)->a, 10))
			sort_stack_a(stacks, 10);
		else
			return ;
	}
	else
	{
		if (!check_sorting_b((*stacks)->b, 10))
			sort_stack_b(stacks, 10);
		else
		{
			push(stacks, STACK_A, 10);
			return ;
		}
	}
	sort_five_handler(stacks, STACK_A);
	sort_five_handler(stacks, STACK_B);
	*/
}

void	sort_nine_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
	{
		if (!check_sorting_a((*stacks)->a, 9))
			sort_stack_a(stacks, 9);
		else
			return ;
	}
	else
	{
		if (!check_sorting_b((*stacks)->b, 9))
			sort_stack_b(stacks, 9);
		else
		{
			push(stacks, STACK_A, 9);
			return ;
		}
	}
	sort_five_handler(stacks, STACK_A);
	sort_four_handler(stacks, STACK_B);
}

void	sort_eight_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
	{
		if (!check_sorting_a((*stacks)->a, 8))
		sort_stack_a(stacks, 8);
		else
		return ;
	}
	else
	{
		if (!check_sorting_b((*stacks)->b, 8))
			sort_stack_b(stacks, 8);
		else
		{
			push(stacks, STACK_A, 8);
			return ;
		}
	}
	sort_four_handler(stacks, STACK_A);
	sort_four_handler(stacks, STACK_B);
}

void	sort_seven_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
	{
		if (!check_sorting_a((*stacks)->a, 7))
		sort_stack_a(stacks, 7);
		else
		return ;
	}
	else
	{
		if (!check_sorting_b((*stacks)->b, 7))
			sort_stack_b(stacks, 7);
		else
		{
			push(stacks, STACK_A, 7);
			return ;
		}
	}
	sort_four_handler(stacks, STACK_A);
	three_handler_b(3, stacks);
}

void	sort_six_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
	{
		if (!check_sorting_a((*stacks)->a, 6))
			sort_stack_a(stacks, 6);
		else
			return ;
	}
	else
	{
		if (!check_sorting_b((*stacks)->b, 6))
			sort_stack_b(stacks, 6);
		else
		{
			push(stacks, STACK_A, 6);
			return ;
		}
	}
	three_handler_a(3, stacks);
	three_handler_b(3, stacks);
}

void	sort_four_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
	{
		if (!check_sorting_a((*stacks)->a, 4))
		sort_stack_a(stacks, 4);
		else
			return ;
	}
	else
	{
		if (!check_sorting_b((*stacks)->b, 4))
			sort_stack_b(stacks, 4);
		else
		{
			push(stacks, STACK_A, 4);
			return ;
		}
	}
	two_handler(stacks, STACK_A);
	two_handler(stacks, STACK_B);
}

void	sort_five_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
	{
		if (!check_sorting_a((*stacks)->a, 5))
		sort_stack_a(stacks, 5);
		else
			return ;
	}
	else
	{
		if (!check_sorting_b((*stacks)->b, 5))
			sort_stack_b(stacks, 5);
		else
		{
			push(stacks, STACK_A, 5);
			return ;
		}
	}
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
