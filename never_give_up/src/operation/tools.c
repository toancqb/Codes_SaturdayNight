/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:27:05 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 12:27:06 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void ft_error()
{
  ft_putstr("Error\n");
  exit(-1);
}

void ft_ok()
{
  ft_putstr("OK\n");
  exit(1);
}

void ft_ko()
{
  ft_putstr("KO\n");
  exit(0);
}

void f_p(int val)
{
//  printf("(%d)\n", val);
  ft_putchar('(');
  ft_putnbr(val);
  ft_putstr(")\n");
}

void swap_int(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

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
				swap_int(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}
