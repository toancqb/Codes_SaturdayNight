/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:14 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:26:08 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

/*
*	Tasks:
*	 - Input: 1 2 3 4 | "1 2 3 4" | 1 "2" "3 4" | 1 " " 2 "3"
*  - Errors : Dup number, max Int, op non valide, non numeric
*
* Sort 3ps, 5ps (ok)
*
*/

void ft_rev_op(t_st **a, t_st **b)
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

void	push_swap(int argc, char **argv)
{
	t_st	*a;
	t_st	*b;
	long		*input;
	int		*select;
	int		len;

	len = 0;
	input = NULL;
	st_init_2stacks(&a, &b);
	input = ft_process_input(argc, argv, &len);
	select = (int*)malloc(sizeof(int) * len);
	ft_init_push_swap(&a, input, select, len);
	if (len <= 3)
		ps_3(&a, len);
	else if (len <= 5)
		ps_5(&a, &b, len);
	if (ft_rev(a))
	{
		ft_rev_op(&a, &b);
		exit(0);
	}
	ft_select(select, len);
	ft_a_to_b(&a, &b, input, select, len);
	ft_align_a_min_max(&a, st_nb_elem(a));
	ft_b_to_a(&a, &b);
	ft_align_a(&a, st_nb_elem(a));
	ft_free_2arr(&input, &select);
	st_free_2stacks(&a, &b);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	else
		push_swap(argc, argv);

	return (0);
}
