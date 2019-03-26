/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:41:11 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 14:41:33 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void printf_st(t_st *st)
{
  int i;

  //printf("is empty: %d | nb elem: %d\n", st_is_empty(st), st_nb_elem(st));
  if (st_is_empty(st) == 0)
  {
    i = st->top;
    while (i >= st->bot)
    {
      printf("(%d)\n", st->tab[in(i)]);
      i--;
    }
  }
  printf("\n=--=\n");
}

void check_st(t_st *a, int len)
{
  int i;

  if (st_nb_elem(a) == len)
  {
      i = a->top;
      while (i > a->bot)
      {
        if (a->tab[in(i)] >= a->tab[in(i - 1)])
          ft_ko();
        i--;
      }
      ft_ok();
  }
  else
    ft_ko();
}

int main(int argc, char *argv[])
{
  t_st *a;
  t_st *b;
  char *line;
  int *input;
  ssize_t size;
  int len;

  len = 0;
  input = NULL;
  a = st_init();
  b = st_init();
  input = ft_process_input(argc, argv, &len);
  ft_init_checker(a, b, input, len);
  free(input);
  while ((size = get_next_line(STDIN_DEFAULT, &line)) > 0)
  {
    ft_command(line, a, b);
    //printf_st(a);
    free(line);
  }
  if (size == -1)
  {
    ft_putstr("zz\n");
    ft_error();
  }
  printf_st(a);
  check_st(a, len);
  free(a);
  free(b);
  return (0);
}
