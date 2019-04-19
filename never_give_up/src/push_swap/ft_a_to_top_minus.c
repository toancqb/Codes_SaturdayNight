/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:07:19 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 16:07:20 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void mtopa_minus(t_st **a, int index)
{
  int i;

  i = 0;
  while (i < index + 1)
  {
    ft_putstr("ra\n");
    ra(a);
    i++;
  }
}

void mbota_minus(t_st **a, int index)
{
  int len_a;
  int i;

  len_a = st_nb_elem(*a);
  i = 0;
  while (i < len_a - index - 1)
  {
    ft_putstr("rra\n");
    rra(a);
    i++;
  }
}

void ft_a_to_top_minus(t_st **a, int rank)
{
  int len_a;
  int index;
  t_elem *e;

  len_a = st_nb_elem(*a);
  index = 0;
  e = (*a)->st_l;
  while (e != NULL)
  {
    if (e->r == rank)
      break ;
    index++;
    e = e->prev;
  }
  if (index == 0)
  {
    ft_putstr("ra\n");
    ra(a);
  }
  else if (index <= len_a / 2)
    mtopa_minus(a, index);
  else if (index > len_a / 2)
    mbota_minus(a, index);
  else
    return;
}
