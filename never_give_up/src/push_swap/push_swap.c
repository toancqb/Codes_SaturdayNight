/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:14 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 19:48:02 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

void	ft_rev_op(t_st **a, t_st **b)
{
	while (st_nb_elem(*a) > 0)
	{
		ft_putstr("rra\npb\n");
		rra(a);
		pb(a, b);
	}
	while (st_nb_elem(*b) > 0)
	{
		ft_putstr("pa\n");
		pa(a, b);
	}
}

void	ft_ps_3_5(t_st **a, t_st **b, int len)
{
	if (len <= 3)
	{
		ps_3(a, len);
	}
	else if (len > 3 && len <= 5)
	{
		ps_5(a, b, len);
	}
}

void	push_swap(int argc, char **argv)
{
	t_st	*a;
	t_st	*b;
	long	*input;
	int		*select;
	int		len;

	len = 0;
	st_init_2stacks(&a, &b);
	input = ft_process_input(argc, argv, &len);
	select = (int*)malloc(sizeof(int) * len);
	ft_init_push_swap(&a, input, select, len);
	if (len <= 5)
		ft_ps_3_5(&a, &b, len);
	else if (ft_rev(a))
		ft_rev_op(&a, &b);
	else
	{
		ft_select(select, len);
		ft_a_to_b(&a, &b, input, select);
		ft_align_a_min_max(&a, st_nb_elem(a));
		ft_b_to_a(&a, &b);
		ft_align_a(&a, st_nb_elem(a));
	}
	ft_free_2arr(&input, &select);
	st_free_2stacks(&a, &b);
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	else
		push_swap(argc, argv);
	return (0);
}
