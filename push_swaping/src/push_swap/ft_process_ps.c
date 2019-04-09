/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:59:35 by qtran             #+#    #+#             */
/*   Updated: 2019/03/06 15:59:36 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void ft_sort_array(int *arr, int len)
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
				swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

void ft_assign_res(t_env *vn)
{
	int i;
	int j;
	int *tmp;

	vn->res = (int*)malloc(sizeof(int) * (vn->len));
	vn->cb = (int*)malloc(sizeof(int) * (vn->len));
	tmp = (int*)malloc(sizeof(int) * (vn->len));
	i = 0;
	while (i < vn->len)
	{
		tmp[i] = vn->org[i];
		vn->cb[i] = 0;
		i++;
	}
	ft_sort_array(tmp, vn->len);
	i = 0;
	while (i < vn->len)
	{
		j = 0;
		while (j < vn->len)
		{
			if (vn->org[i] == tmp[j])
			{
				vn->res[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
  free(tmp);
}
