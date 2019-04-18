/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_ab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:52 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 12:26:55 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"
#include "../stack/st_lib_stack.h"

void rra(t_st **st_a)
{
  t_st *a;
  t_elem *tmp;

  a = *st_a;
  if (st_nb_elem(a) >= 2)
  {
    tmp = a->st_l;
    while (tmp->prev != NULL)
      tmp = tmp->prev;
    a->st_f = tmp->next;
    a->st_f->prev = NULL;
    tmp->next = NULL;
    a->st_l->next = tmp;
    tmp->prev = a->st_l;
    a->st_l = tmp;
  }
}

void rrb(t_st **st_b)
{
  rra(st_b);
}

void rrr(t_st **st_a, t_st **st_b)
{
  rra(st_a);
  rra(st_b);
}
