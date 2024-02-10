/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:19:19 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/10 12:01:21 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stacks **stacks)
{
	t_stacks	**p;

	p = stacks;
	while ((*p)->b)
	{
	}
}

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
	//ft_printf("OK\n");
	clear_stacks(stacks);
	exit(EXIT_SUCCESS);
}

void	sort_three(t_stacks **stacks)
{
	t_stacks	**p;
	t_lnode		*pivot;

	p = stacks;
	pivot = llstlast((*p)->a);
	if ((*p)->a->nbr == (*p)->max)
		ra(stacks);
	else if ((*p)->a->next->nbr == (*p)->max)
		rra(stacks);
	if ((*p)->a->nbr > (*p)->a->next->nbr)
		sa(stacks);
}

void	sort_four(t_stacks **stacks)
{
	t_stacks	**p;
	t_lnode		*pivot;
	int			small;

	p = stacks;
	small = smallest((*p)->a);
	pivot = llstlast((*p)->a);
	if ((*p)->a->next->nbr == small)
		sa(stacks);
	else if (pivot->prev->nbr == small)
	{
		ra(stacks);
		ra(stacks);
	}
	else if (pivot->nbr == small)
		rra(stacks);
	check_sorting(stacks);
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}

void	sort_five(t_stacks **stacks)
{
	t_stacks	**p;
	t_lnode		*pivot;
	int			small;

	p = stacks;
	small = smallest((*p)->a);
	pivot = llstlast((*p)->a);
	if ((*p)->a->next->nbr == small)
		sa(stacks);
	else if ((*p)->a->next->next->nbr == small)
	{
		ra(stacks);
		ra(stacks);
	}
	else if ((*p)->a->next->next->next->nbr == small)
	{
		rra(stacks);
		rra(stacks);
	}
	else if (pivot->prev->nbr == small)
		rra(stacks);
	check_sorting(stacks);
	pb(stacks);
	sort_four(stacks);
	pa(stacks);
}
