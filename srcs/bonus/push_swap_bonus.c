/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:39:45 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/26 20:17:54 by rde-mour         ###   ########.org.br   */
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
	t_lnode	*p;

	while (*argv && *argv != (void *)0)
	{
		if (!(**argv))
			ft_error(stacks);
		check_number(stacks, *argv);
		nbr = ft_atol(*argv++);
		if (nbr < PS_MIN || nbr > PS_MAX)
			ft_error(stacks);
		p = llstnew(nbr);
		llstadd_back(&(*stacks)->a, p);
		check_duplicate(stacks, p);
	}
	(*stacks)->size_a = llstsize((*stacks)->a);
	(*stacks)->size_b = 0;
}

static void	checker(t_stacks **stacks, int argc)
{
	char	*move;

	while (1)
	{
		move = get_next_line(STDIN_FILENO);
		if (!move)
			break ;
		sorting(stacks, &move);
		print_stacks(stacks);
		free(move);
	}
	check_sorting(stacks);
}

// TEMPORARY FUNCTIONS ---------------------------------------------------------
void	print_stacks(t_stacks **stacks)
{
	t_lnode	*a;
	t_lnode	*b;

	a = (*stacks)->a;
	b = (*stacks)->b;
	while (a || b)
	{
		if (a)
		{
			ft_printf("a: %d", a->nbr);
			a = a->next;
		}
		if (b)
		{
			ft_printf("\t\tb: %d", b->nbr);
			b = b->next;
		}
		ft_printf("\n");
	}
}
// TEMPORARY FUNCTIONS ---------------------------------------------------------

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
	checker(&stacks, argc - 1);
	//ft_printf("PRINT ORDER:\n");
	print_stacks(&stacks);
	clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}
