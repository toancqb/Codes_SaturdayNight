/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:48:30 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 15:48:31 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int in(int n)
{
  if (n < 0)
    return (n % NB_MAX + NB_MAX);
  return (n % NB_MAX);
}

void swap(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

char		*ft_strjoin_customed(char *str, char *buf)
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

int val_to_pos(t_st *a, int n)
{
  int i;

  i = a->bot;
  while (i <= a->top)
  {
    if (n == a->tab[in(i)])
      return (i - a->bot);
    i++;
  }
  return (-1);
}

int val_to_rank(t_env *vn, int n)
{
  int i;

  i = 0;
  while (i < vn->len)
  {
    if (n == vn->org[i])
      return (vn->res[i]);
    i++;
  }
  return (-1);
}

int rank_to_pos_a(t_env *vn, int rank)
{
  int i;

  i = 0;
  while (i < vn->len)
  {
    if (vn->res[i] == rank)
      break ;
    i++;
  }
  if (i == vn->len)
    return (-1);
  return (val_to_pos(vn->a, vn->org[i]));
}

int rank_to_pos_b(t_env *vn, int rank)
{
  int i;

  i = 0;
  while (i < vn->len)
  {
    if (vn->res[i] == rank)
      break ;
    i++;
  }
  if (i == vn->len)
    return (-1);
  return (val_to_pos(vn->b, vn->org[i]));
}
