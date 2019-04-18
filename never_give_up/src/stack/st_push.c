/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:31:04 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 12:31:06 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "st_lib_stack.h"

void st_push(t_st **st, t_elem *elem)
{
  if ((*st)->st_f == NULL && (*st)->st_l == NULL)
  {
    elem->next = NULL;
    elem->prev = NULL;
    (*st)->st_f = elem;
    (*st)->st_l = elem;
  }
  else if ((*st)->st_f && (*st)->st_l)
  {
    (*st)->st_l->next = elem;
    elem->prev = (*st)->st_l;
    (*st)->st_l = elem;
  }
}
