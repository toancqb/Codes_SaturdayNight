/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:52:57 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 19:49:23 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int		fcmax(t_st *a)
{
	t_elem	*e;
	int		tmp;
	int		index;
	int		i;

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

void	ps_3ing(t_st **a, int imax)
{
	if (imax == 0)
	{
		ft_putstr("ra\n");
		ra(a);
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

void	ps_3_elem(t_st **a)
{
	t_elem	*e;
	int		imax;

	imax = fcmax(*a);
	e = (*a)->st_l;
	if (e->v > e->prev->v && e->prev->v > e->prev->prev->v)
	{
		ft_putstr("ra\nsa\n");
		ra(a);
		sa(*a);
	}
	else
	{
		ps_3ing(a, imax);
	}
}

void	ps_3(t_st **a, int len)
{
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
	if (!((*a)->st_l->v < (*a)->st_l->prev->v
				&& (*a)->st_l->prev->v < (*a)->st_l->prev->prev->v))
		ps_3_elem(a);
}
