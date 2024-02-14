/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:58:38 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/13 21:48:09 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_handler_a(t_stacks **stacks)
{
	int	mid;
	int	pushs;
	int rotates;

	pushs = 2;
	rotates = 0;
	mid = middler((*stacks)->a, 4);
	while (pushs)
	{
		if ((*stacks)->a->nbr < mid && pushs--)
			push(stacks, STACK_B, 1);
		else if (++rotates)
			rotate(stacks, STACK_A, 1);
	}
	reverse(stacks, STACK_A, rotates);
}

void	sort_four_handler_b(t_stacks **stacks)
{
	int	mid;
	int	pushs;
	int rotates;

	pushs = 2;
	rotates = 0;
	mid = middler((*stacks)->b, 4);
	while (pushs)	
	{
		if ((*stacks)->b->nbr >= mid && pushs--)
			push(stacks, STACK_A, 1);
		else if (++rotates)
			rotate(stacks, STACK_B, 1);
	}
	reverse(stacks, STACK_B, rotates);
}

void	sort_four_handler(t_stacks **stacks, int flag)
{
	if (flag == STACK_A)
		sort_four_handler_a(stacks);
	else
		sort_four_handler_b(stacks);
	two_handler(stacks, STACK_A);
	two_handler(stacks, STACK_B);
}
