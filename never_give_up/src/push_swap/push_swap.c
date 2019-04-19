/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:14 by qtran             #+#    #+#             */
/*   Updated: 2019/04/18 12:26:15 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void push_swap(int argc, char **argv)
{
  t_st *a;
  t_st *b;
  int *input;
  int *select;
  int len;

  len = 0;
  input = NULL;
  a = st_init_stack();
  b = st_init_stack();
  input = ft_process_input(argc, argv, &len);
  select = (int*)malloc(sizeof(int) * len);
  ft_init_push_swap(a, input, select, len);
  ft_select(select, len);
  ft_a_to_b(&a, &b, input, select, len);
  ft_b_to_a(&a, &b);
  ft_align_a(&a, st_nb_elem(a));
  free(input);
  free(select);
  //st_f_inverse_val(a, &f_p, 0); ft_putstr("=--=\n");
  st_free_stack(&a);
  st_free_stack(&b);
}

int main(int argc, char *argv[])
{
  push_swap(argc, argv);

  return (0);
}
