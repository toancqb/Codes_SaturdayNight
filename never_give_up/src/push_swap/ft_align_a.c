/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:25:42 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 12:25:44 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void ft_align_up_down(t_st **a, int times, int cmd)
{
  while(times >= 0)
  {
    if (cmd)
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

int rank_to_index_a(t_st *a, int rank)
{
  t_elem *e;
  int index;

  index = 0;
  e = a->st_l;
  while (e != NULL)
  {
    if (e->r == rank)
      break ;
    index++;
    e = e->prev;
  }
  return (index);
}

void ft_align_a(t_st **a, int len) // len_a + len_b
{
  int pos_min;
  int pos_max;

  pos_min = rank_to_index_a(*a, 0);
  pos_max = rank_to_index_a(*a, len - 1);
  if (pos_min + 1 < len - 1 - pos_max)
    ft_align_up_down(a, pos_min,1);
  else
    ft_align_up_down(a, len - 1 - pos_max, 0);
}
