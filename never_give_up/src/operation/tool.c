#include "../../includes/ft_lib_push_swap.h"

int ft_rev(t_st *a)
{
	t_elem *tmp;

	tmp = a->st_l;
	while (tmp->prev != NULL)
	{
		if (tmp->v < tmp->prev->v)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

void ft_free_2arr(long **i, int **j)
{
	free(*i);
	free(*j);
}

void ft_free_one_tab(char ***tab)
{
	int i;

	if (tab)
	{
		i = 0;
		while ((*tab)[i] != NULL)
		{
			free((*tab)[i]);
			i++;
		}
		free(*tab);
	}
}
