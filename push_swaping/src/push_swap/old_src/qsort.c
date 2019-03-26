/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:13:07 by qtran             #+#    #+#             */
/*   Updated: 2019/03/11 12:13:09 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int partition(int tab[], int l, int h)
{
    int x = tab[in(h)];
    int i = (l - 1);

    for (int j = l; j <= h- 1; j++)
    {
        if (tab[in(j)] <= x)
        {
            i++;
            swap (&tab[in(i)], &tab[in(j)]);
        }
    }
    swap (&tab[in(i + 1)], &tab[in(h)]);
    return (i + 1);
}

void qsort_interative(int *tab, int l, int h)
{
  t_st *st;
  int p;

  st = st_init();
  st_push(st, l);
  st_push(st, h);
  p = 0;
  while (st_is_empty(st) == 0)
  {
    h = st_pop(st);
    l = st_pop(st);
    p = partition(tab, l, h);
    if (p - 1 > l)
    {
      st_push(st, l);
      st_push(st, p - 1);
    }
    if (p + 1 < h)
    {
      st_push(st, p + 1);
      st_push(st, h);
    }
  }
  //free(st);
}
