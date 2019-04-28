/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:08 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 18:00:31 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int		maxi(int a, int b)
{
	return ((a >= b) ? a : b);
}

void	ft_assign_track(int *select, int *p, int max, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		select[i] = 0;
		i++;
	}
	i = max;
	while (1)
	{
		select[i] = 1;
		i = p[i];
		if (i == -1)
			break ;
	}
}

void	ft_init_best_p(int *best, int *p, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		best[i] = 1;
		p[i] = -1;
		i++;
	}
}

void	ft_select(int *select, int len)
{
	int i[3];
	int *p[2];

	i[2] = 0;
	p[0] = (int*)malloc(sizeof(int) * len);
	p[1] = (int*)malloc(sizeof(int) * len);
	ft_init_best_p(p[0], p[1], len);
	while (i[0] < len)
	{
		i[1] = 0;
		while (i[1] < i[0])
		{
			if (select[i[0]] < select[i[1]] && p[0][i[0]] < p[0][i[1]] + 1)
			{
				p[0][i[0]] = p[0][i[1]] + 1;
				p[1][i[0]] = i[1];
				if (p[0][i[2]] < p[0][i[0]])
					i[2] = i[0];
			}
			i[1]++;
		}
		i[0]++;
	}
	ft_assign_track(select, p[1], i[2], len);
	ft_free_2intarr(&p[0], &p[1]);
}
