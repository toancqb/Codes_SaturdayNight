/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:27:05 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:16:40 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void	swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_array(int *arr, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
				swap_int(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

char	*ft_strjoin_customed(char *str, char *buf)
{
	char	*str_return;
	int		len;
	int		i;

	if (str && buf)
	{
		str_return = ft_strnew(ft_strlen(str) + ft_strlen(buf));
		i = 0;
		while (str[i] != '\0')
		{
			str_return[i] = str[i];
			i++;
		}
		len = 0;
		while (buf[len] != '\0')
		{
			str_return[i + len] = buf[len];
			len++;
		}
		str_return[i + len] = '\0';
		free(str);
		return (str_return);
	}
	return (str);
}

int		is_rank_in_a(t_st *a, int rank)
{
	t_elem *e;

	e = a->st_l;
	while (e != NULL)
	{
		if (e->r == rank)
			return (1);
		e = e->prev;
	}
	return (0);
}
