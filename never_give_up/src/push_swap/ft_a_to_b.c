/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:25:35 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:20:34 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int		ft_is_f(int val, long *input, int *select, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (val == (int)input[i])
			return (select[i]);
		i++;
	}
	return (-1);
}

int		ft_f_in_a(t_st *a, long *input, int *select, int len)
{
	t_elem *e;

	e = a->st_l;
	while (e != NULL)
	{
		if (ft_is_f(e->v, input, select, len) == 0)
			return (1);
		e = e->prev;
	}
	return (0);
}

void	ft_a_to_b(t_st **a, t_st **b, long *input, int *select)
{
	int len;

	len = st_nb_elem(*a) + st_nb_elem(*b);
	while (ft_f_in_a(*a, input, select, len))
	{
		if (!ft_is_f((*a)->st_l->v, input, select, len))
		{
			ft_putstr("pb\n");
			pb(a, b);
		}
		else
		{
			ft_putstr("rra\n");
			rra(a);
		}
	}
}
