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

void mtopa(t_st *a, int index)
{
  int i;

  i = 0;
  while (i < index)
  {
    ft_putstr("ra\n");
    ra(a);
    i++;
  }
}

void mbota(t_st *a, int index)
{
  int len_a;
  int i;

  len_a = st_nb_elem(a);
  i = 0;
  while (i < len_a - index)
  {
    ft_putstr("rra\n");
    rra(a);
    i++;
  }
}

void ft_a_to_top(t_st *a, int rank)
{
  int len_a;
  int index;

  len_a = st_nb_elem(a);
  if (index == 0)
    return;
  else if (index <= len_a / 2)
    mtopa(a, index);
  else if (index > len_a / 2)
    mbota(a, index);
  else
  {
    ft_putstr("rra\n");
    rra(a);
  }
}
