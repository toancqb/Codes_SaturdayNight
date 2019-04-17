#include "../../includes/ft_lib_push_swap.h"
#include "../stack/st_lib_stack.h"

void rra(t_st *st_a)
{
  t_elem *tmp;

  if (st_nb_elem(st_a) >= 2)
  {
    tmp = st_a->st_f;
    st_a->st_f = tmp->next;
    st_a->st_f->prev = NULL;
    tmp->next = NULL;
    tmp->prev = st_a->st_l;
    st_a->st_l = tmp;
  }
}

void rrb(t_st *st_b)
{
  rra(st_b);
}

void rrr(t_st *st_a, t_st *st_b)
{
  rra(st_a);
  rrb(st_b);
}
