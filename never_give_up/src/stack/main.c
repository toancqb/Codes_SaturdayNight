#include "st_lib_stack.h"
#include "../../includes/ft_lib_push_swap.h"
#include <stdio.h>

void f_p(int val)
{
  printf("(%d)\n", val);
}

void test_st()
{
  t_st *st;
  t_st *b;
  t_elem *elem;

  st = st_init_stack();
  b = st_init_stack();
  st_push(&st, st_init_elem(10, 0));
  st_push(&st, st_init_elem(20, 0));
  st_push(&st, st_init_elem(30, 0));
  st_push(&st, st_init_elem(40, 0));
  st_push(&st, st_init_elem(50, 0));
  elem = st_pop(&st);
  st_free_elem(&elem);
  st_push(&st, st_init_elem(60, 0));
  st_f_inverse_val(st, &f_p);
  printf("=---=\n");
  //pb(&st, &b);
  //pb(&st, &b);
  st_push(&b, st_pop(&st));
  st_f_inverse_val(st, &f_p);
  printf("=---=\n");
  //st_f_inverse_val(b, &f_p);
}

int main(int argc, char *argv[])
{
  test_st();
  return (0);
}