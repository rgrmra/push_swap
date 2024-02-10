/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:18:27 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/10 13:38:01 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest(t_lnode *stack)
{
	t_lnode	*node;
	int		smallest;

	node = stack;
	smallest = node->nbr;
	while (node)
	{
		if (node->nbr < smallest)
			smallest = node->nbr;
		node = node->next;
	}
	return (smallest);
}

int	biggest(t_lnode *stack)
{
	t_lnode	*node;
	int		biggest;

	node = stack;
	biggest = node->nbr;
	while (node)
	{
		if (node->nbr > biggest)
			biggest = node->nbr;
		node = node->next;
	}
	return (biggest);
}

void	init_counters(t_counters *counters)
{
	counters->ra = 0;
	counters->rb = 0;
	counters->pa = 0;
	counters->pb = 0;
}

void	set_pivots(t_lnode *stack, t_counters *counters)
{
	int	min;
	int	max;

	min = smallest(stack);
	max = biggest(stack);
	counters->big = (min + max) / 2;
	counters->small = (min + counters->big) / 2;
}
