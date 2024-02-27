/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:42:47 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/26 19:03:47 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	llstclear(t_lnode **stack)
{
	t_lnode	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

void	clear_stacks(t_stacks **stacks)
{
	if (stacks && (*stacks)->a)
		llstclear(&((*stacks)->a));
	if (stacks && (*stacks)->b)
		llstclear(&((*stacks)->b));
	if (stacks)
		free(*stacks);
}

void	ft_error(t_stacks **stacks)
{
	clear_stacks(stacks);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
