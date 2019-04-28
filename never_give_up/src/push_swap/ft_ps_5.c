#include "../../includes/ft_lib_push_swap.h"

void ps_5(t_st **a, t_st **b, int len)
{
	int i;

	i = len;
	while (i > 3)
	{
		ft_putstr("pb\n");
		pb(a, b);
		i--;
	}
	ps_3(a, 3);
	ft_b_to_a(a, b);
	ft_align_a(a, st_nb_elem(*a));
	exit(0);
}
