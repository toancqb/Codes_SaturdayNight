#include "st_lib_stack.h"

t_st *st_init_stack()
{
  t_st *st;

  st = (t_st*)malloc(sizeof(t_st));
  st->st_f = NULL;
  st->st_l = NULL;
  return (st);
}
