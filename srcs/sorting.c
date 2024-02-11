/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:19:19 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/11 20:54:09 by rde-mour         ###   ########.org.br   */
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
	print_stacks(stacks);
	clear_stacks(stacks);
	exit(EXIT_SUCCESS);
}
/*
void	sort_two(t_stacks **stacks, int flag)
{
	t_lnode **p;

	if (flag == STACK_A)
		p = &(*stacks)->a;
	else
		p = &(*stacks)->b;
	if ((*p)->nbr > (*p)->next->nbr)
		swap(stacks, flag);
}

void	sort_three(t_stacks **stacks, int flag)
{
	t_lnode 	**p;
	int			big;

	if (flag == STACK_A)
		p = &(*stacks)->a;
	else
		p = &(*stacks)->b;
	big = biggest(*p, llstsize(*p));
	if ((*p)->nbr == big)
		rotate(stacks, flag, 1);
	else if ((*p)->next->nbr == big)
		reverse(stacks, flag, 1);
	if ((*p)->nbr > (*p)->next->nbr)
		swap(stacks, flag);
}

void	sort_four(t_stacks **stacks, int flag)
{
	t_lnode		**p;
	int			small;

	if (flag == STACK_A)
		p = &(*stacks)->a;
	else
		p = &(*stacks)->b;
	small = smallest(*p, llstsize(*p));
	if ((*p)->next->nbr == small)
		swap(stacks, flag);
	else if ((*p)->next->next->nbr == small)
		rotate(stacks, flag, 2);
	else if ((*p)->next->next->next->nbr == small)
		reverse(stacks, flag, 1);
	check_sorting(stacks);
	push(stacks, STACK_B, 1);
	sort_three(stacks, flag);
	push(stacks, flag, 1);
}

void	sort_five(t_stacks **stacks)
{
	t_stacks	**p;
	t_lnode		*pivot;
	int			small;

	p = stacks;
	small = smallest((*p)->a, llstsize((*p)->a));
	pivot = llstlast((*p)->a);
	if ((*p)->a->next->nbr == small)
		swap(stacks, STACK_A);
	else if ((*p)->a->next->next->nbr == small)
		rotate(stacks, STACK_A, 2);
	else if ((*p)->a->next->next->next->nbr == small)
		reverse(stacks, STACK_A, 2);
	else if (pivot->nbr == small)
		reverse(stacks, STACK_A, 1);
	check_sorting(stacks);
	push(stacks, STACK_B, 1);
	sort_four(stacks, STACK_A);
	push(stacks, STACK_A, 1);
}
*/
