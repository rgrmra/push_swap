/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:18:27 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/23 13:57:59 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smaller(t_lnode *stack, int size)
{
	t_lnode	*node;
	int		small;

	node = stack;
	small = node->nbr;
	while (node && size--)
	{
		if (node->nbr < small)
			small = node->nbr;
		if (node->next)
			node = node->next;
	}
	return (small);
}

int	bigger(t_lnode *stack, int size)
{
	t_lnode	*node;
	int		big;

	node = stack;
	big = node->nbr;
	while (node && size--)
	{
		if (node->nbr > big)
			big = node->nbr;
		if (node->next)
			node = node->next;
	}
	return (big);
}

int	middler(t_lnode *stack, int range, int size)
{
	t_lnode	*tmp;
	int		i;
	int		min;
	int		big;
	int		small;

	big = bigger(stack, size);
	small = smaller(stack, size);
	while (--range)
	{
		min = small;
		tmp = stack;
		i = 0;
		while (tmp && i++ < size)
		{
			if (tmp->nbr > min && tmp->nbr < big)
				min = tmp->nbr;
			tmp = tmp->next;
		}
		big = min;
	}
	return (min);
}

void	init_counters(t_lnode *stack, t_counters *counters, int size)
{
	counters->big = middler(stack, size / 2, llstsize(stack));
	counters->small = middler(stack, size / 4 * 3, llstsize(stack));
	counters->ra = 0;
	counters->rb = 0;
	counters->pa = 0;
	counters->pb = 0;
}
