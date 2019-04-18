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

void ft_select(int *select, int len)
{
  int *best, i, j, max = 0;
  int *p;

  best = (int*) malloc ( sizeof( int ) * len );
  p = (int*) malloc ( sizeof( int ) * len );
  for ( i = 0; i < len; i++ )
  {
    best[i] = 1;
    p[i] = -1;
  }
  for ( i = 1; i < len; i++ )
  {    for ( j = 0; j < i; j++ )
      {

          if ( select[i] < select[j] && best[i] < best[j] + 1 )
          {
            best[i] = best[j] + 1;
            p[i] = j;
            if(best[max] < best[i])
                  max = i;
           }
       }
  }
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
  free(best);
  free(p);
}

/*void ft_select(t_st *a, int *input, int len)
{
  t_elem *e;

  lis(input, len);
  e = a->st_l;

}*/
