/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:44:03 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 15:44:04 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void rra(t_st *st_a)
{
  int tmp;

  if (st_nb_elem(st_a) >= 2)
  {
      tmp = st_a->tab[in(st_a->bot++)];
      st_push(st_a, tmp);
  }
}

void rrb(t_st *st_b)
{
  rra(st_b);
}

void rrr(t_st *st_a, t_st *st_b)
{
  rra(st_a);
  rrb(st_b);
}
