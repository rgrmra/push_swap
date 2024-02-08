/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:39:45 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/05 21:07:26 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	check_duplicate(t_stacks **stacks, t_lnode *p)
{
	t_lnode	*tmp;

	tmp = (*stacks)->a;
	while (tmp->next)
	{
		if (tmp->nbr == p->nbr)
			ft_error(stacks);
		tmp = tmp->next;
	}
}

static void	build_stack(t_stacks **stacks, char **argv)
{
	long	nbr;
	t_lnode	*p;

	while (*argv)
	{
		check_number(stacks, *argv);
		nbr = ft_atol(*argv++);
		if (nbr < INT_MIN || nbr > INT_MAX)
			ft_error(stacks);
		p = llstnew(nbr);
		if (nbr < (*stacks)->min)
			(*stacks)->min = nbr;
		if (nbr > (*stacks)->max)
			(*stacks)->max = nbr;
		llstadd_back(&(*stacks)->a, p);
		check_duplicate(stacks, p);
	}
	(*stacks)->sa = llstsize((*stacks)->a);
	(*stacks)->sb = 0;
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

void	sort(t_stacks **stacks, int argc)
{
	t_stacks	**p;
	t_lnode		*pivot;

	p = stacks;
	pivot = llstlast((*p)->a);
	if (argc == 2 && (*p)->a->nbr > pivot->nbr)
		sa(stacks);
	if (argc == 3)
		sort_three(stacks);
	if (argc == 4)
		sort_four(stacks);
	if (argc == 5)
		sort_five(stacks);
	else
		sorting(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		ft_error(NULL);
	stacks = (t_stacks *) ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (EXIT_FAILURE);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->min = INT_MAX;
	stacks->max = INT_MIN;
	build_stack(&stacks, &(*(argv + 1)));
	sort(&stacks, argc - 1);
	ft_printf("PRINT ORDER:\n");
	print_stacks(&stacks);
	clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}
