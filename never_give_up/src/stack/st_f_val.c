#include "st_lib_stack.h"

void st_f_val(t_st *st, void (*f)(int val))
{
  t_elem *tmp;

  if (st)
  {
    tmp = st->st_f;
    while (tmp != NULL)
    {
      (*f)(tmp->v);
      tmp = tmp->next;
    }
  }
}
