/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_f_inverse_val.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:27:33 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 12:27:34 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "st_lib_stack.h"

void st_f_inverse_val(t_st *st, void (*f)(int val), int c)
{
  t_elem *tmp;

  if (st)
  {
    tmp = st->st_l;
    while (tmp != NULL)
    {
      if (!c)
        (*f)(tmp->v);
      else
        (*f)(tmp->r);
      tmp = tmp->prev;
    }    
  }
}
