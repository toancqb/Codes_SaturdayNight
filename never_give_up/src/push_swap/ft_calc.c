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

int is_rank_in_a(t_st *a, int rank)
{
  t_elem *e;

  e = a->st_l;
  while (e != NULL)
  {
    if (e->r == rank)
      return (1);
    e = e->prev;
  }
  return (0);
}

int find_suit_next_rank(t_st *a, int rank, int len_ab, int *r, int *c)
{
  t_elem *e;
  int r_max;
  int r_min;

  *r = 0;
  *c = 0;
  e = a->st_l;
  r_max = len_ab;
  r_min = -1;
  while (e != NULL)
  {
    if (e->r > rank && e->r < r_max)
      r_max = e->r;
    if (e->r < rank && e->r > r_min)
      r_min = e->r;
    e = e->prev;
  }
  if (r_max == len_ab)
  {
    rank = r_min;
    *c = 1;
  }
  else
  {
    //rank = r_max;
    rank++;
    while (!is_rank_in_a(a, rank))
      rank++;
  }
  *r = rank;
  return (1);
}

int ft_calc_b(t_st *a, t_st *b, int index, int rank, int *rrr, int *check)
{
  int len_a;
  int len_b;
  int ch_tmp;
  int r_tmp;

  len_a = st_nb_elem(a);
  len_b = st_nb_elem(b);
  ch_tmp = 0;
  //if (find_suit_next_rank(a, rank, len_a + len_b, &r_tmp, &ch_tmp) == -1)
  //  return (9999999);
  find_suit_next_rank(a, rank, len_a + len_b, &r_tmp, &ch_tmp);
  *rrr = r_tmp;
  *check = ch_tmp;
  return (ft_calc_a_rank_to_top(a, r_tmp, len_a)
  + ft_calc_index_to_top(index, len_b) + 1);
}

int ft_calc_b_to_a(t_st *a, t_st *b, int *rr, int *check)
{
  t_elem *e;
  int index;
  int ch_tmp;
  int rrr;
  int min[3];

  min[0] = 0;
  index = 0;
  e = b->st_l;
  min[1] = ft_calc_b(a, b, 0, e->r, &rrr, check);
  *rr = rrr;
  if (e->prev == NULL)
    return (0);
  e = e->prev;
  index++;
  while (e != NULL)
  {
    min[2] = ft_calc_b(a, b, index, e->r, &rrr, &ch_tmp);
    if (min[1] > min[2])
    {
      min[1] = min[2];
      min[0] = index;
      *rr = rrr;
      *check = ch_tmp;
    }
    index++;
    e = e->prev;
  }
  return (min[0]);
}
