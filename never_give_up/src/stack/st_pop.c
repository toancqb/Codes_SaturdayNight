/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:30:57 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:08:01 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "st_lib_stack.h"

t_elem	*st_pop(t_st **st)
{
	t_elem	*tmp;

	tmp = NULL;
	if ((*st)->st_f && (*st)->st_l)
	{
		if ((*st)->st_f != (*st)->st_l)
		{
			tmp = (*st)->st_f;
			while (tmp->next != (*st)->st_l)
				tmp = tmp->next;
			(*st)->st_l = tmp;
			tmp = tmp->next;
			(*st)->st_l->next = NULL;
		}
		else if ((*st)->st_f == (*st)->st_l)
		{
			tmp = (*st)->st_f;
			(*st)->st_f = NULL;
			(*st)->st_l = NULL;
		}
		return (tmp);
	}
	return (NULL);
}
