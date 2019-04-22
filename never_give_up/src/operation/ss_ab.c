/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_ab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:59 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:19:45 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"
#include "../stack/st_lib_stack.h"

void	sa(t_st *st_a)
{
	t_elem	*tmp;
	int		t;

	if (st_nb_elem(st_a) >= 2)
	{
		tmp = st_a->st_l->prev;
		t = tmp->v;
		tmp->v = st_a->st_l->v;
		st_a->st_l->v = t;
		t = tmp->r;
		tmp->r = st_a->st_l->r;
		st_a->st_l->r = t;
	}
}

void	sb(t_st *st_b)
{
	sa(st_b);
}

void	ss(t_st *a, t_st *b)
{
	sa(a);
	sb(b);
}
