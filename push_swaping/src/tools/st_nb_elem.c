/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_nb_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:12:24 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 15:12:25 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int st_nb_elem(t_st *st)
{
  int nb;

  nb = st->top - st->bot + 1;
  return ((nb > 0) ? nb : 0);
}
