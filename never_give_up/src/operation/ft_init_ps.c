/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:01 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 17:56:14 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

int		ft_count_len_input(int argc, char **argv)
{
	int		len;
	int		i;
	int		j;
	char	**tab;

	len = 0;
	i = 1;
	while (i < argc)
	{
		tab = ft_strsplit(argv[i], ' ');
		j = 0;
		while (tab[j] != NULL)
			j++;
		len += j;
		i++;
		ft_free_one_tab(&tab);
	}
	return (len);
}

void	ft_check_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0' && str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error();
		i++;
	}
}

void	ft_check_dup(long *input, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (input[i] == input[j])
				ft_error();
			j++;
		}
		i++;
	}
}

void	ft_assign_input_argv(long *input, int *j, char *argv)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(argv, ' ');
	i = 0;
	while (tab[i] != NULL)
	{
		ft_check_input(tab[i]);
		input[*j] = ft_atoi_long(tab[i]);
		if (input[*j] > INT_MAX || input[*j] < INT_MIN)
			ft_error();
		i++;
		(*j)--;
	}
	ft_free_one_tab(&tab);
}

long	*ft_process_input(int argc, char **argv, int *len)
{
	int		i;
	int		j;
	long	*input;

	*len = ft_count_len_input(argc, argv);
	input = (long*)malloc(sizeof(long) * (*len));
	i = 1;
	j = *len - 1;
	while (i < argc && j >= 0)
	{
		ft_assign_input_argv(input, &j, argv[i]);
		i++;
	}
	ft_check_dup(input, *len);
	return (input);
}
