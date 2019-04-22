/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:25:48 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:23:41 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void	top_bot(t_st **a, t_st **b, int c, char **ins)
{
	if (!c)
	{
		*ins = ft_strjoin_customed(*ins, "pa\n");
		pa(a, b);
	}
	else
	{
		*ins = ft_strjoin_customed(*ins, "rrb\npa\n");
		rrb(b);
		pa(a, b);
	}
}

void	mtop(t_st **a, t_st **b, int index, char **ins)
{
	int i;

	i = 0;
	while (i < index)
	{
		*ins = ft_strjoin_customed(*ins, "rb\n");
		rb(b);
		i++;
	}
	*ins = ft_strjoin_customed(*ins, "pa\n");
	pa(a, b);
}

void	mbot(t_st **a, t_st **b, int index, char **ins)
{
	int len_b;
	int i;

	len_b = st_nb_elem(*b);
	i = 0;
	while (i < len_b - index)
	{
		*ins = ft_strjoin_customed(*ins, "rrb\n");
		rrb(b);
		i++;
	}
	*ins = ft_strjoin_customed(*ins, "pa\n");
	pa(a, b);
}

void	ft_b_to_top_and_pa(t_st **a, t_st **b, int index, char **ins)
{
	int len_b;

	len_b = st_nb_elem(*b);
	if (index == 0)
		top_bot(a, b, 0, ins);
	else if (index <= len_b / 2)
		mtop(a, b, index, ins);
	else if (index > len_b / 2)
		mbot(a, b, index, ins);
	else
		top_bot(a, b, 1, ins);
}

void	ft_free_tab(char **ta, char **tb)
{
	int i;

	i = 0;
	while (ta[i] != NULL)
	{
		free(ta[i]);
		i++;
	}
	i = 0;
	while (tb[i] != NULL)
	{
		free(tb[i]);
		i++;
	}
}

void	ft_rr_rrr(char **ins_a, char **ins_b)
{
	char	**ta;
	char	**tb;
	int		i;
	int		j;

	ta = ft_strsplit(*ins_a, '\n');
	tb = ft_strsplit(*ins_b, '\n');
	free(*ins_a);
	*ins_a = ft_strnew(1);
	i = 0;
	j = 0;
	while (ta[i] != NULL)
	{
		if (tb[j] != NULL && ft_strequ(ta[i], "ra") && ft_strequ(tb[j], "rb"))
		{
			*ins_a = ft_strjoin_customed(*ins_a, "rr\n");
			i++;
			j++;
			continue ;
		}
		if (tb[j] != NULL && ft_strequ(ta[i], "rra") && ft_strequ(tb[j], "rrb"))
		{
			*ins_a = ft_strjoin_customed(*ins_a, "rrr\n");
			i++;
			j++;
			continue ;
		}
		*ins_a = ft_strjoin_customed(*ins_a, ta[i]);
		*ins_a = ft_strjoin_customed(*ins_a, "\n");
		i++;
	}
	while (tb[j] != NULL)
	{
		*ins_a = ft_strjoin_customed(*ins_a, tb[j]);
		*ins_a = ft_strjoin_customed(*ins_a, "\n");
		j++;
	}
	ft_free_tab(ta, tb);
}

void	ft_b_to_a(t_st **a, t_st **b)
{
	int		index;
	int		check;
	int		rr;
	char	*ins_a;
	char	*ins_b;

	index = 0;
	while (st_nb_elem(*b) > 0)
	{
		ins_a = ft_strnew(1);
		ins_b = ft_strnew(1);
		check = 0;
		index = ft_calc_b_to_a(*a, *b, &rr, &check);
		if (check == 0)
			ft_a_to_top(a, rr, &ins_a);
		else
			ft_a_to_top_minus(a, rr, &ins_a);
		ft_b_to_top_and_pa(a, b, index, &ins_b);
		ft_rr_rrr(&ins_a, &ins_b);
		ft_putstr(ins_a);
		free(ins_a);
		free(ins_b);
	}
}
