#include "st_lib_stack.h"

void st_push(t_st **st, t_elem *elem)
{
  if ((*st)->st_f == NULL && (*st)->st_l == NULL)
  {
    //elem->next = NULL;
    //elem->prev = NULL;
    (*st)->st_f = elem;
    (*st)->st_l = elem;
  }
  else if ((*st)->st_l)
  {
    (*st)->st_l->next = elem;
    elem->prev = (*st)->st_l;
    (*st)->st_l = elem;
  }
}
