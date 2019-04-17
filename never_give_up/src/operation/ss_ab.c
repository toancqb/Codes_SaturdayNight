#include "../../includes/ft_lib_push_swap.h"

void swap_int(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

void sa(t_st *st_a)
{
  t_elem *tmp;
  int t;

  if (st_nb_elem(st_a) >= 2)
  {
    tmp = st_a->st_l->prev;
    t = tmp->v;
    tmp->v = st_a->st_l->v;
    st_a->st_l->v = t;
    t = tmp->r;
    tmp->r = st_a->st_l->r;
    st_a->st_l->r = t;
  }
}

void sb(t_st *st_b)
{
  sa(st_b);
}

void ss(t_st *a, t_st *b)
{
  sa(a);
  sb(b);
}
