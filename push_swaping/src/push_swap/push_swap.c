/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:08:02 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 19:08:03 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

/*
gcc push_swap.c ft_pb.c ft_pa.c ft_init.c process.c ft_select.c
../tools/.c ../checker/ft_process_input.c ../checker/ft_display_checker.c
../../libft/libft.a
*/

int *ft_process_input_push_old(int argc, char **argv, int *len)
{
  char **tab;
  int i;
  int *input;

  *len = 0;
  if (argc >= 2)
  {
    tab = ft_strsplit(argv[1], ' ');
    while (tab[*len] != NULL)
      (*len)++;
    input = (int*)malloc(sizeof(int) * (*len));
    i = 0;
    while (i < *len && tab[i])
    {
      input[i] = (int)ft_atoi(tab[i]);
      i++;
    }
    i = 0;
    while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
    free(tab);
    return (input);
  }
  else
    ft_error();
  return (NULL);
}

void env_init(t_env *vn)
{
  vn->a = st_init();
  vn->b = st_init();
  vn->len = 0;
  vn->org = NULL;
  vn->res = NULL;
  //vn->ins = NULL;
}

void ft_init_push_swap(t_env *vn, int len)
{
  int i;
  int tmp;

  i = len - 1;
  while (i >= 0)
  {
    tmp = (vn->org)[i];
    st_push(vn->a, tmp);
    i--;
  }
  if (st_is_empty(vn->a))
    ft_ok();
}

void ft_free(t_env **v, t_ps **p)
{
  t_env *vn;
  t_ps *ps;

  vn = *v;
  ps = *p;
  free(vn->org);
  free(vn->res);
  free(vn->cb);
  free(vn->a);
  free(vn->b);
}

int main(int argc, char *argv[])
{
	t_env *vn;
  t_ps *ps;

  ps = ft_init_ps();
  vn = (t_env*)malloc(sizeof(t_env));
  env_init(vn);
	vn->org = ft_process_input_push_old(argc, argv, &(vn->len));
	ft_assign_res(vn);
	ft_init_push_swap(vn, vn->len);
  push_swap(vn, ps);
  //printf_ps(vn->a);
  ft_free(&vn, &ps);
  free(vn);
  free(ps);
  return (0);
}
