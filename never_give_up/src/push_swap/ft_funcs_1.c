/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:57:25 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 17:57:27 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int		is_sorted_st(t_st *a, int len)
{
	t_elem	*tmp;

	if (st_nb_elem(a) == len)
	{
		tmp = a->st_l;
		while (tmp->prev != NULL)
		{
			if (tmp->v > tmp->prev->v)
				return (0);
			tmp = tmp->prev;
		}
		return (1);
	}
	else
		return (0);
}

void	ft_assign_rank(t_st *a, int len, int *tmp)
{
	t_elem	*e;
	int		i;

	e = a->st_l;
	while (e != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (e->v == tmp[i])
				e->r = i;
			i++;
		}
		e = e->prev;
	}
}

void	ft_init_push_swap(t_st **a, long *input, int *select, int len)
{
	int		i;
	int		*tmp;

	i = 0;
	tmp = (int*)malloc(sizeof(int) * (len));
	while (i < len)
	{
		tmp[i] = (int)input[i];
		select[i] = (int)input[i];
		st_push(a, st_init_elem((int)input[i], 0));
		i++;
	}
	if (is_sorted_st(*a, len))
		exit(0);
	ft_sort_array(tmp, len);
	ft_assign_rank(*a, len, tmp);
	free(tmp);
}
