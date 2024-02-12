/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:58:38 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/11 21:01:36 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_five_handler_a(t_stacks **stacks, int size)
{
	int	mid;
	int	tpush;
	int trotate;

	tpush = 0;
	trotate = 0;
	mid = middle((*stacks)->a);
	while (size--)
	{
		if ((*stacks)->a->nbr < mid)
		{
			push(stacks, STACK_B, 1);
			tpush++;
		}
		else 
		{
			rotate(stacks, STACK_A, 1);
			trotate++;
		}
		if (tpush == 2)
			break ;
	}
	while (trotate--)
		reverse(stacks, STACK_A, 1);
}

static void	sort_five_handler_b(t_stacks **stacks, int size)
{
	int	mid;
	int	tpush;
	int trotate;

	tpush = 0;
	trotate = 0;
	mid = middle((*stacks)->b);
	while (size--)
	{
		if ((*stacks)->b->nbr >= mid)
		{
			push(stacks, STACK_A, 1);
			tpush++;
		}
		else
		{
			rotate(stacks, STACK_B, 1);
			trotate++;
		}
		if (tpush == 3)
			break ;
	}
	while (trotate--)
		reverse(stacks, STACK_B, 1);
}

void	five_handler(t_stacks **stacks)
{
	int	pb;
	int	mid;

	pb = 2;
	mid = middle((*stacks)->a);
	while (pb)
	{
		if ((*stacks)->a->nbr < mid)
		{
			push(stacks, STACK_B, 1);
			pb--;
		}
		else 
			rotate(stacks, STACK_A, 1);
	}
	three_handler_a(3, stacks);
	two_handler(stacks, STACK_B);
}

void	sort_five_handler(int size, t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
		sort_five_handler_a(stacks, size);
	else
		sort_five_handler_b(stacks, size);
	three_handler_a(3, stacks);
	two_handler(stacks, STACK_B);
}
