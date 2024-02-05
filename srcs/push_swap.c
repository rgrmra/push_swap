/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:39:45 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/04 22:43:24 by rde-mour         ###   ########.org.br   */
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
/*
void	print_rev_stacks(t_stacks **stacks)
{
	t_lnode	*a;
	t_lnode	*b;

	a = llstlast((*stacks)->a);
	b = llstlast((*stacks)->b);
	while (a || b)
	{
		if (a)
		{
			ft_printf("a: %d", a->nbr);
			a = a->prev;
		}
		if (b)
		{
			ft_printf("\tb: %d", b->nbr);
			b = b->prev;
		}
		ft_printf("\n");
	}
}
*/
// TEMPORARY FUNCTIONS ---------------------------------------------------------

void	check_sorting(t_stacks **stacks)
{
	t_lnode	*node;

	if ((*stacks)->b)
		return ;
	node = (*stacks)->a;
	while (node)
	{
		if (node->next && node->nbr > node->next->nbr)
			break ;
		node = node->next;
	}
	if (node)
		return;
	ft_printf("OK\n");
	clear_stacks(stacks);
	exit(EXIT_SUCCESS);
}

void	sort_three(t_stacks **stacks)
{
	t_stacks	**p;
	t_lnode		*pivot;

	p = stacks;
	pivot = llstlast((*p)->a);
	if ((*p)->a->nbr == (*p)->max)
		ra(stacks);
	else if ((*p)->a->next->nbr == (*p)->max)
		rra(stacks);
	if ((*p)->a->nbr > (*p)->a->next->nbr)
		sa(stacks);
}

void	sort_four(t_stacks **stacks)
{
	t_stacks	**p;
	t_lnode		*pivot;

	p = stacks;
	pivot = llstlast((*p)->a);
	if ((*p)->a->next->nbr == (*p)->min)
		sa(stacks);
	else if (pivot->prev->nbr == (*p)->min)
	{
		ra(stacks);
		ra(stacks);
	}
	else if (pivot->nbr == (*p)->min)
		rra(stacks);
	check_sorting(stacks);
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}

void	sort_five(t_stacks **stacks)
{
	t_stacks	**p;
	t_lnode		*pivot;

	p = stacks;
	pivot = llstlast((*p)->a);
	if ((*p)->a->next->nbr == (*p)->min)
		sa(stacks);
	else if ((*p)->a->next->next->nbr == (*p)->min)
	{
		ra(stacks);
		ra(stacks);
	}
	else if ((*p)->a->next->next->next->nbr == (*p)->min)
	{
		rra(stacks);
		rra(stacks);
	}
	else if (pivot->prev->nbr == (*p)->min)
		rra(stacks);
	check_sorting(stacks);
	pb(stacks);
	sort_four(stacks);
	pa(stacks);
}

int	smallest(t_stacks *stacks, t_lnode **stack, int *smallest)
{
	t_lnode	*node;
	size_t	moves;

	node = *stack;
	*smallest = node->nbr;
	moves = 0;
	while (node)
	{
		if (node->nbr < *smallest)
			*smallest = node->nbr;
		node = node->next;
		moves++;
	}
	if (stacks->sa / 2 < moves)
		return (ASC);
	else
		return (DESC);
}

void	sorting(t_stacks **stacks)
{
	t_stacks	**p;
	t_lnode		*pivota;
	t_lnode		*pivotb;

	p = stacks;
	if ((*p)->a->nbr == (*p)->max)
		ra(stacks);
	pb(stacks);
	while ((*p)->a)
	{
		pivota = llstlast((*p)->a);
		pivotb = llstlast((*p)->b);
		if ((*p)->sa > 1 && pivota->nbr < (*p)->a->nbr
			&& (*p)->sb > 1 && pivotb->nbr > (*p)->b->nbr)
			rrr(stacks);
		else if ((*p)->sa > 1 && pivota->nbr < (*p)->a->nbr)
			rra(stacks);
		else if ((*p)->sb > 1 && pivotb->nbr > (*p)->b->nbr)
			rrb(stacks);
		if ((*p)->sa > 1 && (*p)->a->nbr > (*p)->a->next->nbr
			&& (*p)->sb > 1 && (*p)->a->nbr < (*p)->b->next->nbr)
			ss(stacks);
		else if ((*p)->sa > 1 && (*p)->a->nbr > (*p)->a->next->nbr)
			sa(stacks);
		else if ((*p)->sb > 1 && (*p)->b->nbr < (*p)->b->next->nbr)
			sb(stacks);
		if ((*p)->sa > 1 && (*p)->a->nbr < pivota->nbr
			&& (*p)->sb > 1 && (*p)->b->nbr < pivotb->nbr)
			rr(stacks);
		else if ((*p)->sa > 1 && (*p)->a->nbr < pivota->nbr)
			ra(stacks);
		else if ((*p)->sb > 1 && (*p)->b->nbr < pivotb->nbr)
			rb(stacks);
		if ((*p)->a->nbr > (*p)->b->nbr)
			pb(stacks);
		else if ((*p)->a->nbr < pivotb->nbr)
		{
			pb(stacks);
			rb(stacks);
		}
		else if ((*p)->a->nbr > pivotb->nbr)
		{
			pivotb = (*p)->a;
			pb(stacks);
			rb(stacks);
			while ((*p)->b->nbr > pivotb->nbr)
				pa(stacks);
			rrb(stacks);
		}
		//print_stacks(stacks);
	}
	while ((*p)->b)
		pa(stacks);
}

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
	//ft_printf("PRINT REVERSE ORDER:\n");
	//print_rev_stacks(&stacks);
	//ft_printf("min: %d\t\tmax: %d\n", stacks->min, stacks->max);
	clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}
