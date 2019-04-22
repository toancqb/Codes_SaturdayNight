/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:25:42 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:22:20 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void	ft_align_up_down(t_st **a, int times, int cmd)
{
	while(times >= 0)
	{
		if (!cmd)
		{
			ft_putstr("rra\n");
			rra(a);
		}
		else
		{
			ft_putstr("ra\n");
			ra(a);
		}
		times--;
	}
}

int		rank_to_index_a(t_st *a, int rank, int len)
{
	t_elem	*e;
	int		index;

	index = 0;
	e = a->st_l;
	while (e != NULL && index < len)
	{
		if (e->r == rank)
			break ;
		index++;
		e = e->prev;
	}
	return (index);
}

/*
 *  len = len_a + len_b
 */
void	ft_align_a(t_st **a, int len) 
{
	int pos_min;
	int pos_max;

	pos_min = rank_to_index_a(*a, 0, len);
	pos_max = rank_to_index_a(*a, len - 1, len);
	if (pos_min + 1 < len - 1 - pos_max)
		ft_align_up_down(a, pos_min - 1, 1);
	else
		ft_align_up_down(a, len - pos_max - 2, 0);
}

/*
 *  len = len_a + len_b
 */
void	ft_align_a_min_max(t_st **a, int len)
{
	int		pos_min;
	int		pos_max;
	int		i;
	int		j;
	t_elem	*e;

	e = (*a)->st_l;
	i = e->r;
	j = e->r;
	e = e->prev;
	while (e != NULL)
	{
		if (i > e->r)
			i = e->r;
		if (j < e->r)
			j = e->r;
		e = e->prev;
	}
	pos_min = rank_to_index_a(*a, i, len);
	pos_max = rank_to_index_a(*a, j, len);
	if (pos_min + 1 < j - pos_max)
		ft_align_up_down(a, pos_min - 1, 1);
	else
		ft_align_up_down(a, j - pos_max - 1, 0);
}
