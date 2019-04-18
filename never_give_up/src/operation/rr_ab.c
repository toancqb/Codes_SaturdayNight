/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:46 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 12:26:48 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"
#include "../stack/st_lib_stack.h"

void ra(t_st **st_a)
{
  t_elem *tmp;
  t_elem *tmp2;
  t_st *a;

  a = *st_a;
  if (st_nb_elem(a) >= 2)
  {
    tmp = a->st_l;
    tmp2 = a->st_f;
    a->st_l = a->st_l->prev;
    tmp->prev = NULL;
    tmp->next = tmp2;
    tmp2->prev = tmp;
    a->st_f = tmp;
  }
}

void rb(t_st **st_b)
{
  ra(st_b);
}

void rr(t_st **st_a, t_st **st_b)
{
  ra(st_a);
  rb(st_b);
}
