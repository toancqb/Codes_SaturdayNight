/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:52:26 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 16:52:27 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void ft_command(char *line, t_st *a, t_st *b)
{
  ft_putstr(line); ft_putchar('\n');
  
  if (!ft_strcmp(line, "sa"))
    sa(a);
  if (!ft_strcmp(line, "sb"))
    sb(b);
  if (!ft_strcmp(line, "ss"))
    ss(a, b);
  if (!ft_strcmp(line, "pa"))
    pa(a, b);
  if (!ft_strcmp(line, "pb"))
    pb(b, a);
  if (!ft_strcmp(line, "ra"))
    ra(a);
  if (!ft_strcmp(line, "rb"))
    rb(b);
  if (!ft_strcmp(line, "rr"))
    rr(a, b);
  if (!ft_strcmp(line, "rra"))
    rra(a);
  if (!ft_strcmp(line, "rrb"))
    rrb(b);
  if (!ft_strcmp(line, "rrr"))
    rrr(a, b);
  //else
  //  ft_error();
}
