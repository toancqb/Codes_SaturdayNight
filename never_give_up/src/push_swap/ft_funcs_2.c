/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:57:00 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 20:06:13 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void	ft_free_2intarr(int **best, int **p)
{
	if (best && p)
	{
		free(*best);
		free(*p);
	}
}

void	ft_free_tab(char ***ta, char ***tb)
{
	ft_free_one_tab(ta);
	ft_free_one_tab(tb);
}
