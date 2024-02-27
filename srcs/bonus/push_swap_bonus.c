/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:39:45 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/27 19:47:57 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_number(t_stacks **stacks, char *nbr)
{
	if (!nbr)
		ft_error(stacks);
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	while (ft_isdigit(*nbr))
		nbr++;
	if (*nbr)
		ft_error(stacks);
}

static void	check_duplicate(t_stacks **stacks, t_lnode *node)
{
	t_lnode	*tmp;

	tmp = (*stacks)->a;
	while (tmp->next)
	{
		if (tmp->nbr == node->nbr)
			ft_error(stacks);
		tmp = tmp->next;
	}
}

static void	build_stack(t_stacks **stacks, char **argv)
{
	long	nbr;
	t_lnode	*node;

	while (*argv)
	{
		if (!(**argv))
			ft_error(stacks);
		check_number(stacks, *argv);
		nbr = ft_atol(*argv++);
		if (nbr < PS_MIN || nbr > PS_MAX)
			ft_error(stacks);
		node = llstnew((int) nbr);
		llstadd_back(&(*stacks)->a, node);
		check_duplicate(stacks, node);
	}
}

static void	checker(t_stacks **stacks)
{
	char	*move;

	while (1)
	{
		move = get_next_line(STDIN_FILENO);
		if (!move)
			break ;
		if (!sorter(stacks, move))
		{
			free(move);
			ft_error(stacks);
		}
		free(move);
	}
	check_sorting(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (EXIT_SUCCESS);
	stacks = (t_stacks *) ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		ft_error(&stacks);
	stacks->a = NULL;
	stacks->b = NULL;
	build_stack(&stacks, ++argv);
	checker(&stacks);
	clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}
