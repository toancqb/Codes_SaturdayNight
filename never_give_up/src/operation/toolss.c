/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:12:20 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:17:44 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(-1);
}

void	ft_ok(void)
{
	ft_putstr("OK\n");
	exit(1);
}

void	ft_ko(void)
{
	ft_putstr("KO\n");
	exit(0);
}

void	f_p(int val)
{
	ft_putchar('(');
	ft_putnbr(val);
	ft_putstr(")\n");
}

void	swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
