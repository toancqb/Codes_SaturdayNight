#include "../../includes/ft_lib_push_swap.h"

t_ps *ft_init_ps()
{
  t_ps *ps;

  ps = (t_ps*)malloc(sizeof(t_ps));
  ps->head = 0;
  ps->tail_max = 0;
  ps->tail_min = 0;
  ps->moves = 0;
  ps->next_move = 0;
  ps->ins = ft_strnew(1);
  ps->ins_a = ft_strnew(1);
  ps->ins_b = ft_strnew(1);
  return (ps);
}
