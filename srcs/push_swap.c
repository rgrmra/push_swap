/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:39:45 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/02 19:45:45 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_stacks **stacks)
{
	if (stacks && (*stacks)-> a)
		ps_lstclear(&((*stacks)-> a));
	if (stacks && (*stacks)-> b)
		ps_lstclear(&((*stacks)-> b));
	if (stacks)
		free(*stacks);
}

void	ft_error(t_stacks **stacks)
{
	ft_clear(stacks);
	write(STDERR_FILENO, "Error\n", 6); 
	exit(EXIT_FAILURE);
}

void	build_stack(t_stacks **stacks, char **argv)
{
	size_t	i;

	if (!argv)
		return ;
	i = 0;
	while (*(argv + i))
		ps_lstadd_back(&(*stacks)->a, ps_lstnew(ft_atoi(*(argv + i++))));
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2 && argv)
		ft_error(NULL);
	stacks = (t_stacks *) ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (EXIT_FAILURE);
	stacks -> a = NULL;
	stacks -> b = NULL;
	build_stack(&stacks, &(*(argv + 1)));
	ft_clear(&stacks);
	return (EXIT_SUCCESS);
}
