/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:27:41 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 12:27:42 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "st_lib_stack.h"

void st_free_elem(t_elem **e)
{
  if (e)
  {
    free(*e);
  }
}

void st_free_stack(t_st **st)
{
  t_elem *tmp;
  t_elem *tmp2;

  if (st)
  {
    tmp = (*st)->st_l;
    while (tmp != NULL)
    {
      tmp2 = tmp;
      tmp = tmp->prev;
      st_free_elem(&tmp2);
    }
  }
}
