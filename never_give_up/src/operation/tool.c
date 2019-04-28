/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 18:10:53 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 18:11:17 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int		ft_rev(t_st *a)
{
	t_elem *tmp;

	tmp = a->st_l;
	while (tmp->prev != NULL)
	{
		if (tmp->v < tmp->prev->v)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

void	ft_free_2arr(long **i, int **j)
{
	free(*i);
	free(*j);
}

void	ft_free_one_tab(char ***tab)
{
	int i;

	if (tab)
	{
		i = 0;
		while ((*tab)[i] != NULL)
		{
			free((*tab)[i]);
			i++;
		}
		free(*tab);
	}
}
