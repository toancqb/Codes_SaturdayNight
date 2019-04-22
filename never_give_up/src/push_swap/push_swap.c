/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:14 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:26:08 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

/*
*	Tasks:
*	 - Input: 1 2 3 4 | "1 2 3 4" | 1 "2" "3 4" | 1 " " 2 "3"
*  - Errors : Dup number, max Int, op non valide, non numeric
*
* Sort 3ps, 5ps
*
*/

int fcmax(t_st *a)
{
	t_elem *e;
	int tmp;
	int index;
	int i;

	e = a->st_l;
	tmp = e->v;
	index = 0;
	i = 1;
	e = e->prev;
	while (e != NULL)
	{
		if (e->v > tmp)
		{
			tmp = e->v;
			index = i;
		}
		i++;
		e = e->prev;
	}
	return (index);
}

void ps_3(t_st **a, int len)
{
		int imax;

		if (len == 1)
			exit(0);
		if (len == 2)
		{
			if ((*a)->st_l->v > (*a)->st_l->prev->v)
			{
				ft_putstr("sa\n");
				sa(*a);
			}
			exit(0);
		}
		imax = fcmax(*a);
		if (imax == 0)
		{
			ft_putstr("rra\n");
			rra(a);
		}
		else if (imax == 2)
		{
			ft_putstr("sa\n");
			sa(*a);
		}
		else
		{
			ft_putstr("rra\n");
			rra(a);
			if ((*a)->st_l->v > (*a)->st_l->prev->v)
			{
				ft_putstr("sa\n");
				sa(*a);
			}
		}
		st_f_inverse_val(*a, &f_p, 0);
		ft_putstr("=--=\n");
		exit(0);
}

void ps_3_customed(t_st **a, int len)
{
		int imax;

		if (is_sorted_st(*a, len))
			return;
		if (ft_rev(*a))
		{
			ft_align_a(a, st_nb_elem(*a));
			return;
		}
		imax = fcmax(*a);
		if (imax == 0)
		{
			ft_putstr("rra\n");
			rra(a);
		}
		else if (imax == 2)
		{
			ft_putstr("sa\n");
			sa(*a);
		}
		else
		{
			ft_putstr("rra\n");
			rra(a);
			if ((*a)->st_l->v > (*a)->st_l->prev->v)
			{
				ft_putstr("sa\n");
				sa(*a);
			}
		}
}

void ps_5(t_st **a, t_st **b, int len)
{
	int i;

	i = len;
	while (i > 3)
	{
		ft_putstr("pb\n");
		pb(a, b);
		i--;
	}
	ps_3_customed(a, len);
	ft_b_to_a(a, b);
	ft_align_a(a, st_nb_elem(*a));
	st_f_inverse_val(*a, &f_p, 0);
	ft_putstr("=--=\n");
	exit(0);
}

void	push_swap(int argc, char **argv)
{
	t_st	*a;
	t_st	*b;
	int		*input;
	int		*select;
	int		len;

	len = 0;
	input = NULL;
	st_init_2stacks(&a, &b);
	input = ft_process_input(argc, argv, &len);
	select = (int*)malloc(sizeof(int) * len);
	ft_init_push_swap(&a, input, select, len);
	if (ft_rev(a))
	{
		ft_align_a(&a, st_nb_elem(a));
		exit(0);
	}
	if (len <= 3)
		ps_3(&a, len);
	else if (len <= 5)
		ps_5(&a, &b, len);
	ft_select(select, len); // Day Con tang lon nhat
	ft_a_to_b(&a, &b, input, select, len); // Chuyen sang b tat ca elem False
	ft_align_a_min_max(&a, st_nb_elem(a)); // Dua thanh Day con tang lon nhat
	ft_b_to_a(&a, &b);
	ft_align_a(&a, st_nb_elem(a));
	//st_f_inverse_val(a, &f_p, 0);
	//ft_putstr("=--=\n");
	ft_free_2arr(&input, &select);
	st_free_2stacks(&a, &b);
}

int main(int argc, char *argv[])
{
	push_swap(argc, argv);

	return (0);
}
