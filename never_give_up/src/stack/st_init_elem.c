#include "st_lib_stack.h"

t_elem *st_init_elem(int val, int rank)
{
  t_elem *st;

  st = (t_elem*)malloc(sizeof(t_elem));
  st->v = val;
  st->r = rank;
  st->next = NULL;
  st->prev = NULL;
  return (st);
}
