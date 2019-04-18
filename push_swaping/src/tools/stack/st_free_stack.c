#include "st_lib_stack.h"

void st_free_elem(t_elem **e)
{
  if (e)
  {
    free(*e);
  }
}

void st_free_stack(t_st **st)
{
  t_elem *tmp;

  if (st)
  {
    while ((*st)->st_f != NULL)
    {
      tmp = (*st)->st_f;
      (*st)->st_f = (*st)->st_f->next;
      free(tmp);
    }
  }
}
