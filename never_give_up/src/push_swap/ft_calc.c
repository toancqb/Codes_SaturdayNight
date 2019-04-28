/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:25:56 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 20:47:08 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int	ft_c(int index, int len)
{
	if (index == 0)
		return (0);
	else if (index <= len / 2)
		return (index);
	else if (index > len / 2)
		return (len - index);
	else
		return (1);
}

int	ft_calc_a_rank_to_top(t_st *a, int rank, int len)
{
	t_elem	*e;
	int		index;
	int		check;

	check = 0;
	index = 0;
	e = a->st_l;
	while (e != NULL)
	{
		if (e->r == rank)
		{
			check = 1;
			break ;
		}
		index++;
		e = e->prev;
	}
	if (check == 0)
		return (-1);
	return (ft_c(index, len));
}

int	find_suit_next_rank(t_st *a, int rank, int len_ab, int *c)
{
	int		r_max;
	int		r_min;

	*c = 0;
	r_max = len_ab;
	r_min = -1;
	find_r_minmax(a, &r_max, &r_min, rank);
	if (r_max == len_ab)
	{
		rank = r_min;
		*c = 1;
	}
	else
	{
		rank++;
		while (!is_rank_in_a(a, rank))
			rank++;
	}
	return (rank);
}

int	ft_calc_b(t_st *a, int rank, int *rrr, int *check)
{
	int len_a;
	int ch_tmp;

	len_a = st_nb_elem(a);
	ch_tmp = 0;
	*rrr = find_suit_next_rank(a, rank, *rrr, &ch_tmp);
	*check = ch_tmp;
	return (ft_calc_a_rank_to_top(a, *rrr, len_a) + 1);
}

int	ft_calc_b_to_a(t_st *a, t_st *b, int *rr, int *check)
{
	t_elem	*e;
	int		index;
	int		r[5];

	e = b->st_l;
	ft_1(a, b, &r[2], &r[0]);
	r[3] = ft_calc_b(a, e->r, &r[0], check) + ft_c(0, st_nb_elem(b));
	*rr = r[0];
	if (e->prev == NULL)
		return (0);
	ft_2(&e, &index, 1);
	while (e != NULL)
	{
		r[0] = st_nb_elem(a) + st_nb_elem(b);
		r[4] = ft_calc_b(a, e->r, &r[0], &r[1]) + ft_c(index, st_nb_elem(b));
		if (r[3] > r[4])
		{
			r[3] = r[4];
			r[2] = index;
			*rr = r[0];
			*check = r[1];
		}
		ft_2(&e, &index, 0);
	}
	return (r[2]);
}
