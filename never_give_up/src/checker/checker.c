/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:27 by qtran             #+#    #+#             */
/*   Updated: 2019/04/22 13:03:24 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"
#include "../stack/st_lib_stack.h"

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

void	ft_init_checker(t_st *a, t_st *b, int *input, int len)
{
	int i;
	int tmp;

	i = 0;
	while (i < len)
	{
		tmp = input[i];
		st_push(&a, st_init_elem(tmp, 0));
		i++;
	}
	if (st_nb_elem(a))
		return ;
}

void	ft_command(char *line, t_st **a, t_st **b)
{
	if (ft_strequ(line, "sa"))
		sa(*a);
	else if (ft_strequ(line, "sb"))
		sb(*b);
	else if (ft_strequ(line, "ss"))
		ss(*a, *b);
	else if (ft_strequ(line, "pa"))
		pa(a, b);
	else if (ft_strequ(line, "pb"))
		pb(a, b);
	else if (ft_strequ(line, "ra"))
		ra(a);
	else if (ft_strequ(line, "rb"))
		rb(b);
	else if (ft_strequ(line, "rr"))
		rr(a, b);
	else if (ft_strequ(line, "rra"))
		rra(a);
	else if (ft_strequ(line, "rrb"))
		rrb(b);
	else if (ft_strequ(line, "rrr"))
		rrr(a, b);
	else
		ft_error();
}

void	check_st(t_st *a, int len)
{
	t_elem *tmp;

	if (st_nb_elem(a) == len)
	{
		tmp = a->st_l;
		while (tmp->prev != NULL)
		{
			if (tmp->v > tmp->prev->v)
				ft_ko();
			tmp = tmp->prev;
		}
		ft_ok();
	}
	else
		ft_ko();
}

int		main(int argc, char *argv[])
{
	t_st		*a;
	t_st		*b;
	char		*line;
	int			*input;
	ssize_t		size;
	int			len;

	len = 0;
	input = NULL;
	a = st_init_stack();
	b = st_init_stack();
	input = ft_process_input(argc, argv, &len);
	ft_init_checker(a, b, input, len);
	while ((size = get_next_line(STDIN_DEFAULT, &line)) > 0)
	{
		ft_command(line, &a, &b);
		free(line);
	}
	if (size == -1)
		ft_error();
	check_st(a, len);
	free(input);
	st_free_stack(&a);
	st_free_stack(&b);
	return (0);
}
