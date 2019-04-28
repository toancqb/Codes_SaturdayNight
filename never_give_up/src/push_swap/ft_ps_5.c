/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:54:05 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 17:54:15 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void	ps_5(t_st **a, t_st **b, int len)
{
	int	i;

	i = len;
	while (i > 3)
	{
		ft_putstr("pb\n");
		pb(a, b);
		i--;
	}
	ps_3(a, 3);
	ft_b_to_a(a, b);
	ft_align_a(a, st_nb_elem(*a));
	exit(0);
}
