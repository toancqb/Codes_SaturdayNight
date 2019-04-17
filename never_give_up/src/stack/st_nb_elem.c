#include "st_lib_stack.h"

int st_nb_elem(t_st *st)
{
  int count;
  t_elem *e;

  count = 0;
  if (st)
  {
    e = st->st_l;
    while (e != NULL)
    {
      count++;
      e = e->prev;
    }
  }
  return (count);
}
