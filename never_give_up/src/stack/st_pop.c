#include "st_lib_stack.h"

t_elem *st_pop(t_st **st)
{
  t_elem *tmp;

  if ((*st)->st_l && (*st)->st_f)
  {
    tmp = (*st)->st_f;
    while (tmp->next != (*st)->st_l)
    {
      tmp = tmp->next;
    }
    (*st)->st_l = tmp;
    (*st)->st_l->next = NULL;
    tmp = tmp->next;
    //tmp->next = NULL;
    //tmp->prev = NULL;
    return (tmp);
  }
  return (NULL);
}
