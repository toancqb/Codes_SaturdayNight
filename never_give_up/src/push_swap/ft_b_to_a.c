/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:25:48 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 12:25:50 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void top_bot(t_st **a, t_st **b, int c)
{
  if (!c)
  {
    ft_putstr("pa\n");
    pa(a, b);
  }
  else
  {
    ft_putstr("rrb\npa\n");
    rrb(b);
    pa(a, b);
  }
}

void mtop(t_st **a, t_st **b, int index)
{
  int i;

  i = 0;
  while (i < index)
  {
    ft_putstr("rb\n");
    rb(b);
    i++;
  }
  ft_putstr("pa\n");
  pa(a, b);
}

void mbot(t_st **a, t_st **b, int index)
{
  int len_b;
  int i;

  len_b = st_nb_elem(*b);
  i = 0;
  while (i < len_b - index)
  {
    ft_putstr("rrb\n");
    rrb(b);
    i++;
  }
  ft_putstr("pa\n");
  pa(a, b);
}

void ft_b_to_top_and_pa(t_st **a, t_st **b, int index)
{
  int len_b;

  len_b = st_nb_elem(*b);
  if (index == 0)
    top_bot(a, b, 0);
  else if (index <= len_b / 2)
    mtop(a, b, index);
  else if (index > len_b / 2)
    mbot(a, b, index);
  else
    top_bot(a, b, 1);
}

void ft_b_to_a(t_st **a, t_st **b)
{
  t_elem *e;
  int index;
  int check;
  int rr;

  index = 0;
  while (st_nb_elem(*b) > 0)
  {
    check = 0;
    index = ft_calc_b_to_a(*a, *b, &rr, &check);
    if (check == 0)
    {
      ft_a_to_top(a, rr);
      ft_b_to_top_and_pa(a, b, index);
    }
    else
    {
      ft_a_to_top_minus(a, rr);
      ft_b_to_top_and_pa(a, b, index);
    }
    /*printf("=--=\n");
    st_f_inverse_val(*a, &f_p, 0);
    printf("=--=\n");*/
  }
}
