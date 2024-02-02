/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:35 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/02 19:46:54 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_psnode	*ps_lstnew(int nbr)
{
	t_psnode	*new;

	new = (t_psnode *) ft_calloc(1, sizeof(t_psnode));
	if (!new)
		exit(2);
	new -> nbr = nbr;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}

t_psnode	*ps_lstlast(t_psnode *stack)
{
	t_psnode	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp -> next)
		tmp = tmp -> next;
	return (tmp);
}

void	ps_lstadd_front(t_psnode **stack, t_psnode *new)
{
	if (!stack || !new)
		return ;
	new -> next = *stack;
	(*stack)-> prev = new;
	*stack = new;
}

void	ps_lstadd_back(t_psnode **stack, t_psnode *new)
{
	t_psnode	*tmp;

	if (!stack || !new)
		return ;
	if (!(*stack))
		*stack = new;
	else
	{
		tmp = ps_lstlast(*stack);
		tmp -> next = new;
		new -> prev = tmp;
	}
}

void	ps_lstclear(t_psnode **stack)
{
	t_psnode	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)-> next;
		free(tmp);
	}
	*stack = NULL;
}
