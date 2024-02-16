/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:19:19 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/14 17:55:03 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sorting(t_stacks **stacks)
{
	t_lnode	*node;

	if ((*stacks)->b)
		return ;
	node = (*stacks)->a;
	while (node)
	{
		if (node->next && node->nbr > node->next->nbr)
			break ;
		node = node->next;
	}
	if (node)
		return ;
	clear_stacks(stacks);
	exit(EXIT_SUCCESS);
}

void	sort_three(t_stacks **stacks)
{
	int			big;

	big = bigger((*stacks)->a, (*stacks)->size_a);
	if ((*stacks)->a->nbr == big)
		rotate(stacks, STACK_A, 1);
	else if ((*stacks)->a->next->nbr == big)
		reverse(stacks, STACK_A, 1);
	if ((*stacks)->a->nbr > (*stacks)->a->next->nbr)
		swap(stacks, STACK_A);
}

void	sort_four(t_stacks **stacks)
{
	int			small;

	small = smaller((*stacks)->a, (*stacks)->size_a);
	if ((*stacks)->a->next->nbr == small)
		swap(stacks, STACK_A);
	else if ((*stacks)->a->next->next->nbr == small)
		rotate(stacks, STACK_A, 2);
	else if ((*stacks)->a->next->next->next->nbr == small)
		reverse(stacks, STACK_A, 1);
	check_sorting(stacks);
	push(stacks, STACK_B, 1);
	sort_three(stacks);
	push(stacks, STACK_A, 1);
}

void	sort_five(t_stacks **stacks)
{
	int			small;

	small = smaller((*stacks)->a, (*stacks)->size_a);
	if ((*stacks)->a->next->nbr == small)
		swap(stacks, STACK_A);
	else if ((*stacks)->a->next->next->nbr == small)
		rotate(stacks, STACK_A, 2);
	else if ((*stacks)->a->next->next->next->nbr == small)
		reverse(stacks, STACK_A, 2);
	else if ((*stacks)->a->next->next->next->next->nbr == small)
		reverse(stacks, STACK_A, 1);
	check_sorting(stacks);
	push(stacks, STACK_B, 1);
	sort_four(stacks);
	push(stacks, STACK_A, 1);
}
