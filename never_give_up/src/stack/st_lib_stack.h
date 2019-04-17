#ifndef FT_LIB_STACK_H
# define FT_LIB_STACK_H
# include <stdlib.h>
# include <unistd.h>

typedef struct  s_elem
{
  int v;
  int r;
  struct s_elem *next;
  struct s_elem *prev;
}t_elem;

typedef struct s_st
{
  t_elem *st_f;
  t_elem *st_l;
}t_st;

t_elem *st_init_elem(int val, int rank);
t_st *st_init_stack();

int st_nb_elem(t_st *st);

void st_free_elem(t_elem **e);
void st_free_stack(t_st **st);

void st_push(t_st **st, t_elem *elem);
t_elem *st_pop(t_st **st);

void st_f_val(t_st *st, void (*f)(int val));

#endif
