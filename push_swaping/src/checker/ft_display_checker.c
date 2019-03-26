/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:55:23 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 16:55:24 by qtran            ###   ########.fr       */
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
