/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:08 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 12:26:09 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int maxi(int a, int b)
{
  return ((a >= b)? a : b);
}

void ft_assign_track(int *select, int *p, int max, int len)
{
  int i;

  i = 0;
  while (i < len)
  {
    select[i] = 0;
    i++;
  }
  i = max;
  while (1)
  {
    select[i] = 1;
    i = p[i];
    if (i == -1)
      break ;
  }
}

void ft_init_best_p(int *best, int *p, int len)
{
  int i;

  i = 0;
  while (i < len)
  {
    best[i] = 1;
    p[i] = -1;
    i++;
  }
}

void ft_select(int *select, int len)
{
  int *best;
  int i[3];
  int *p;

  i[2] = 0;
  best = (int*)malloc(sizeof(int) * len);
  p = (int*)malloc(sizeof(int) * len);
  ft_init_best_p(best, p, len);
  while (i[0] < len)
  {
    i[1] = 0;
    while (i[1] < i[0])
    {
      if (select[i[0]] < select[i[1]] && best[i[0]] < best[i[1]] + 1)
      {
        best[i[0]] = best[i[1]] + 1;
        p[i[0]] = i[1];
        if (best[i[2]] < best[i[0]])
          i[2] = i[0];
      }
      i[1]++;
    }
    i[0]++;
  }
  ft_assign_track(select, p, i[2], len);
  free(best);
  free(p);
}
