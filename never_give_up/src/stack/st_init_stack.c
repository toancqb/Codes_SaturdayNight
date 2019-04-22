/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:27:56 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:09:18 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "st_lib_stack.h"

t_st	*st_init_stack(void)
{
	t_st	*st;

	st = (t_st*)malloc(sizeof(t_st));
	st->st_f = NULL;
	st->st_l = NULL;
	return (st);
}

void st_init_2stacks(t_st **a, t_st **b)
{
	*a = st_init_stack();
	*b = st_init_stack();
}
