#include "../../includes/ft_lib_push_swap.h"

int max_st(t_st *st)
{
  int max;
  int i;

  i = st->bot;
  max = st->tab[in(i)];
  i++;
  while (i <= st->top)
  {
    if (max < st->tab[in(i)])
      max = st->tab[in(i)];
    i++;
  }
  return (max);
}

int min_st(t_st *st)
{
  int min;
  int i;

  i = st->bot;
  min = st->tab[in(i)];
  i++;
  while (i <= st->top)
  {
    if (min > st->tab[in(i)])
      min = st->tab[in(i)];
    i++;
  }
  return (min);
}

int max_next(t_st *st, int prev_max)
{
  int i;
  int check;
  int max_next;

  i = st->bot;
  check = 0;
  while (i <= st->top)
  {
    if (st->tab[in(i)] < prev_max)
    {
      if (check && max_next < st->tab[in(i)])
        max_next = st->tab[in(i)];
      if (!check)
      {
        max_next = st->tab[in(i)];
        check = 1;
      }
    }
    i++;
  }
  return (max_next);
}

void move_init()
{
  t_move *mv;

  mv = (t_move*)malloc(sizeof(t_move));
  ins = NULL;
  mv->prev_max = max_st(vn->a);
  mv->min = min_st(vn->a);
  mv->max = max_st(vn->a);

  mv->next_max = 0;
  mv->in_a = MIN64INT;
  mv->in_b = MIN64INT;
}

void main_control(t_env *vn, t_move *mv)
{
  t_move *mv;
  int i;
  int len;

  mv = move_init();
  len = st_nb_elem(vn->a);
  i = 0;
  while (i < len)
  {
    mv->in_a = max_next(vn->a, mv->prev_max);
    mv->in_b = max_next(vn->b, mv->prev_max);
    mv->next_max = (mv->in_a > mv->in_b) ? mv->in_a : mv->in_b;
    best_i_to_j(); //
    i++;
  }
  while (pos(mv->max) != bottom)//
  {
    ra or  rra//
  }
}
