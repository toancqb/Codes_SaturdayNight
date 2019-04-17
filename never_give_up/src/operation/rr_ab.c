#include "../../includes/ft_lib_push_swap.h"

void ra(t_st *st_a)
{
  t_elem *tmp;

  if (st_nb_elem(st_a) >= 2)
  {
    tmp = st_a->st_l;
    st_a->st_l = tmp->prev;
    st_a->st_l->next = NULL;
    tmp->prev = NULL;
    tmp->next = st_a->st_f;
    st_a->st_f->prev = tmp;
    st_a->st_f = tmp;
  }
}

void rb(t_st *st_b)
{
  ra(st_b);
}

void rr(t_st *st_a, t_st *st_b)
{
  ra(st_a);
  rb(st_b);
}
