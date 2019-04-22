/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:01 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:25:07 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int		*ft_process_input(int argc, char **argv, int *len)
{
	char	**tab;
	int		i;
	int		j;
	int		*input;

	*len = 0;
	if (argc >= 2)
	{
		tab = ft_strsplit(argv[1], ' ');
		while (tab[*len] != NULL)
			(*len)++;
		input = (int*)malloc(sizeof(int) * (*len));
		i = 0;
		j = *len - 1;
		while (j >= 0 && tab[i])
		{
			input[j] = (int)ft_atoi(tab[i]);
			j--;
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

int	is_sorted_st(t_st *a, int len)
{
	t_elem *tmp;

	if (st_nb_elem(a) == len)
	{
		tmp = a->st_l;
		while (tmp->prev != NULL)
		{
			if (tmp->v > tmp->prev->v)
				return (0);
			tmp = tmp->prev;
		}
		return (1);
	}
	else
		return (0);
}

void ft_assign_rank(t_st *a, int len, int *tmp)
{
	t_elem *e;
	int i;

	e = a->st_l;
	while (e != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (e->v == tmp[i])
				e->r = i;
			i++;
		}
		e = e->prev;
	}
}

void	ft_init_push_swap(t_st **a, int *input, int *select, int len)
{
	int		i;
	int		*tmp;

	i = 0;
	tmp = (int*)malloc(sizeof(int) * (len));
	while (i < len)
	{
		tmp[i] = input[i];
		select[i] = input[i];
		st_push(a, st_init_elem(input[i], 0));
		i++;
	}
	if (is_sorted_st(*a, len))
		exit(0);
	/*if (ft_rev(*a))
	{
		ft_align_a(a, st_nb_elem(*a));
		exit(0);
	}*/
	ft_sort_array(tmp, len);
	ft_assign_rank(*a, len, tmp);
	free(tmp);
}
