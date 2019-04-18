#include "st_lib_stack.h"

t_elem *st_pop(t_st **st)
{
  t_elem *tmp;

  if ((*st)->st_f && (*st)->st_l)
  {
    if ((*st)->st_f != (*st)->st_l)
    {
      tmp = (*st)->st_f;
      while (tmp->next != (*st)->st_l)
        tmp = tmp->next;
      (*st)->st_l = tmp;      
      tmp = tmp->next;
      (*st)->st_l->next = NULL;
    }
    else if ((*st)->st_f == (*st)->st_l)
    {
      tmp = (*st)->st_f;
      (*st)->st_f = NULL;
      (*st)->st_l = NULL;
    }
    return (tmp);
  }
  return (NULL);
}
