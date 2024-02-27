/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:35 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/26 19:04:20 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_lnode	*llstnew(int nbr)
{
	t_lnode	*new;

	new = (t_lnode *) ft_calloc(1, sizeof(t_lnode));
	if (!new)
		exit(2);
	new->nbr = nbr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

size_t	llstsize(t_lnode *stack)
{
	t_lnode	*node;
	size_t	size;

	if (!stack)
		return (0);
	size = 0;
	node = stack;
	while (node && ++size)
		node = node->next;
	return (size);
}

t_lnode	*llstlast(t_lnode *stack)
{
	t_lnode	*node;

	if (!stack)
		return (NULL);
	node = stack;
	while (node->next)
		node = node->next;
	return (node);
}

void	llstadd_front(t_lnode **stack, t_lnode *new)
{
	if (!stack || !new)
		return ;
	new -> next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

void	llstadd_back(t_lnode **stack, t_lnode *new)
{
	t_lnode	*node;

	if (!stack || !new)
		return ;
	if (!(*stack))
		*stack = new;
	else
	{
		node = llstlast(*stack);
		node->next = new;
		new->prev = node;
	}
}
