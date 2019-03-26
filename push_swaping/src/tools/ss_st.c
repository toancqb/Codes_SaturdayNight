/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:43:23 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 15:43:24 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

static void swap_val(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

void sa(t_st *st)
{
  if (st_nb_elem(st) > 1)
    swap_val(&st->tab[in(st->top)], &st->tab[in(st->top - 1)]);
}

void sb(t_st *st)
{
  sa(st);
}

void ss(t_st *st_a, t_st *st_b)
{
  sa(st_a);
  sb(st_b);
}
