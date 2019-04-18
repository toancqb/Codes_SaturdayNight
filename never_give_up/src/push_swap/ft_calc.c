/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:25:56 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 12:25:57 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int ft_calc_index_to_top(int index, int len)
{
  if (index == 0)
    return (0);
  else if (index <= len / 2)
    return (index);
  else if (index > len / 2)
    return (len - index);
  else
    return (1);
}

int ft_calc_a_rank_to_top(t_st *a, int rank, int len)
{
    t_elem *e;
    int index;
    int check;

    check = 0;
    index = 0;
    e = a->st_l;
    while (e != NULL)
    {
        if (e->r == rank)
        {
          check = 1;
          break ;
        }
        index++;
        e = e->prev;
    }
    if (check == 0)
      return (-1);
    return (ft_calc_index_to_top(index, len));
}

int ft_calc_b(t_st *a, t_st *b, int index, int rank, int *rrr)
{
  int len_a;
  int len_b;
  int tmp;

  len_a = st_nb_elem(a);
  len_b = st_nb_elem(b);
  tmp = rank + 1;
  if (tmp <= len_a + len_b - 1)
  {
    while (ft_calc_a_rank_to_top(a, tmp, len_a) == -1)
    {
      if (tmp == len_a + len_b - 1)
        break ;
      tmp++;
    }
    if (tmp == len_a + len_b - 1 && ft_calc_a_rank_to_top(a, tmp, len_a) == -1)
    {
      rank--;
      while (ft_calc_a_rank_to_top(a, rank, len_a) == -1)
      {
          if (rank == 0)
            break ;
          rank--;
      }
    }
    else
      rank = tmp;
  }
  else if (rank == len_a + len_b - 1)
  {
    rank--;
    while (ft_calc_a_rank_to_top(a, rank, len_a) == -1)
    {
        if (rank == 0)
          break ;
        rank--;
    }
  }
  *rrr = rank;
  return (ft_calc_a_rank_to_top(a, rank, len_a)
  + ft_calc_index_to_top(index, len_b) + 1);
}

int ft_calc_b_to_a(t_st *a, t_st *b, int *rr)
{
  t_elem *e;
  int index;
  int rrr;
  int min[3];

  min[0] = 0;
  index = 0;
  e = b->st_l;
  min[1] = ft_calc_b(a, b, 0, e->r, &rrr);
  *rr = rrr;
  if (e->prev == NULL)
    return (0);
  e = e->prev;
  index++;
  while (e != NULL)
  {
    min[2] = ft_calc_b(a, b, index, e->r, &rrr);
    if (min[1] > min[2])
    {
      min[1] = min[2];
      min[0] = index;
      *rr = rrr;
    }
    index++;
    e = e->prev;
  }
  return (min[0]);
}
