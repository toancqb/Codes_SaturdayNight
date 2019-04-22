/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_init_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:27:49 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:06:16 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "st_lib_stack.h"

t_elem	*st_init_elem(int val, int rank)
{
	t_elem	*st;

	st = (t_elem*)malloc(sizeof(t_elem));
	st->v = val;
	st->r = rank;
	st->next = NULL;
	st->prev = NULL;
	return (st);
}
