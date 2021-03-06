/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:43:38 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 15:43:39 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void pa(t_st *st_a, t_st *st_b)
{
  if (st_is_empty(st_b) == 0)
  {
    st_push(st_a, st_pop(st_b));
  }
}

void pb(t_st *st_b, t_st *st_a)
{
  pa(st_b, st_a);
}
