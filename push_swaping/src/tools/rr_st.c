/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:43:49 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 15:43:50 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void ra(t_st *st_a)
{
  int tmp;

  if (st_nb_elem(st_a) >= 2)
  {
    tmp = st_pop(st_a);
    st_a->tab[in(--st_a->bot)] = tmp;
  }
}

void rb(t_st *st_b)
{
  ra(st_b);
}

void rr(t_st *st_a, t_st *st_b)
{
  ra(st_a);
  rb(st_b);
}
