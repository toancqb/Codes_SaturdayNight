/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 20:16:00 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 20:18:44 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void	ft_process_ins_a(char **ins_a, char *str, int *i, int *j)
{
	*ins_a = ft_strjoin_customed(*ins_a, str);
	(*i)++;
	(*j)++;
}

void	ft_process_ins_a2(char **ins_a, char *str, int *i)
{
	*ins_a = ft_strjoin_customed(*ins_a, str);
	*ins_a = ft_strjoin_customed(*ins_a, "\n");
	(*i)++;
}

void	ft_process_tb(char **ins_a, char **tb, int j)
{
	while (tb[j] != NULL)
		ft_process_ins_a2(ins_a, tb[j], &j);
}

void	ft_f_init(char **ins_a, int *i, int *j)
{
	free(*ins_a);
	*ins_a = ft_strnew(1);
	*i = 0;
	*j = 0;
}

void	ft_rr_rrr(char **ins_a, char **ins_b)
{
	char	**ta;
	char	**tb;
	int		i;
	int		j;

	ta = ft_strsplit(*ins_a, '\n');
	tb = ft_strsplit(*ins_b, '\n');
	ft_f_init(ins_a, &i, &j);
	while (ta[i] != NULL)
	{
		if (tb[j] != NULL && ft_strequ(ta[i], "ra") && ft_strequ(tb[j], "rb"))
		{
			ft_process_ins_a(ins_a, "rr\n", &i, &j);
			continue ;
		}
		if (tb[j] != NULL && ft_strequ(ta[i], "rra") && ft_strequ(tb[j], "rrb"))
		{
			ft_process_ins_a(ins_a, "rrr\n", &i, &j);
			continue ;
		}
		ft_process_ins_a2(ins_a, ta[i], &i);
	}
	ft_process_tb(ins_a, tb, j);
	ft_free_tab(&ta, &tb);
}
