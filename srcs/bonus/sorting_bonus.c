/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:19:19 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/27 19:47:27 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_sorting(t_stacks **stacks)
{
	t_lnode	*node;

	node = (*stacks)->a;
	while (node)
	{
		if (node->next && node->nbr > node->next->nbr)
			break ;
		node = node->next;
	}
	if (node || (*stacks)->b)
		ft_putendl_fd("KO", STDOUT_FILENO);
	else
		ft_putendl_fd("OK", STDOUT_FILENO);
	clear_stacks(stacks);
	exit(EXIT_SUCCESS);
}

int	sorter(t_stacks **stacks, char *move)
{
	if (!ft_strncmp(move, "sa\n", 5))
		swap(stacks, STACK_A);
	else if (!ft_strncmp(move, "sb\n", 5))
		swap(stacks, STACK_B);
	else if (!ft_strncmp(move, "ss\n", 5))
		swap(stacks, STACKS);
	else if (!ft_strncmp(move, "pa\n", 5))
		push(stacks, STACK_A);
	else if (!ft_strncmp(move, "pb\n", 5))
		push(stacks, STACK_B);
	else if (!ft_strncmp(move, "ra\n", 5))
		rotate(stacks, STACK_A);
	else if (!ft_strncmp(move, "rb\n", 5))
		rotate(stacks, STACK_B);
	else if (!ft_strncmp(move, "rr\n", 5))
		rotate(stacks, STACKS);
	else if (!ft_strncmp(move, "rra\n", 5))
		reverse(stacks, STACK_A);
	else if (!ft_strncmp(move, "rrb\n", 5))
		reverse(stacks, STACK_B);
	else if (!ft_strncmp(move, "rrr\n", 5))
		reverse(stacks, STACKS);
	else
		return (FAILURE);
	return (SUCCESS);
}
