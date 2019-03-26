/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_is_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:12:30 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 15:12:31 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int st_is_empty(t_st *st)
{
  return ((int)(st->top < st->bot));
}
