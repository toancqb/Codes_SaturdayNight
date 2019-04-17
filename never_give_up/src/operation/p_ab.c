#include "../../includes/ft_lib_push_swap.h"

void pa(t_st **st_a, t_st **st_b)
{
  if (st_nb_elem(*st_b) >= 1)
    st_push(st_a, st_pop(st_b));
}

void pb(t_st **st_a, t_st **st_b)
{
  if (st_nb_elem(*st_a) >= 1)
    st_push(st_b, st_pop(st_a));
}
