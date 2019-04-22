/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_nb_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:30:49 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:07:47 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "st_lib_stack.h"

int	st_nb_elem(t_st *st)
{
	int		count;
	t_elem	*e;

	count = 0;
	if (st)
	{
		e = st->st_l;
		while (e != NULL)
		{
			count++;
			e = e->prev;
		}
	}
	return (count);
}
