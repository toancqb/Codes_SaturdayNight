#include "../../includes/ft_lib_push_swap.h"

void upper(t_env *vn, int pos, int len, t_ps *ps)
{
  while (pos < len - 1)
  {
    ps->ins = ft_strjoin_customed(ps->ins, "ra\n");
    ps->next_move++;
    ra(vn->a);
    pos++;
  }
}

void lower(t_env *vn, int pos, int len, t_ps *ps)
{
  while (pos >= 0)
  {
    ps->ins = ft_strjoin_customed(ps->ins, "rra\n");
    ps->next_move++;
    rra(vn->a);
    pos--;
  }
}

int pos_to_top(t_env *vn, int pos, t_ps *ps)
{
  int place;
  int len;

  len = st_nb_elem(vn->a);
  place = place_elem(vn->a, pos);
  if (place == 1)
  {
    upper(vn, pos, len, ps);
  }
  else if(place == 3)
  {
    ps->next_move++;
    ps->ins = ft_strjoin_customed(ps->ins, "rra\n");
    rra(vn->a);
  }
  else
  {
    lower(vn, pos, len, ps);
  }
  return (ps->next_move);
}
/*
* Try new algo:
* calc for each elem by rank, choose the smallest ins
* repeat
*
*/

void put_elem_to_suit_pos(t_env *vn, int rank, t_ps *ps)
{
  int pos;

  //if (rank != vn->len - 1)
  //{
    pos = rank_to_pos_a(vn, rank);
    push_a_to_b(vn, pos, ps);
    pos_to_top(vn, rank_to_pos_a(vn, rank + 1), ps);
    ps->next_move++;
    ps->ins = ft_strjoin_customed(ps->ins, "pa\n");
    pa(vn->a, vn->b);
  //}
}

int ft_check(t_env *vn, int *cb)
{
  int i;

  i = 0;
  while (i <= vn->len - 1)
  {
    if (cb[i] != 1)
      return (1);
    i++;
  }
  return (0);
}

int ft_is_check(t_env *vn, int rank)
{
  int i;

  i = 0;
  while (i <= vn->len - 1)
  {
    if (vn->res[i] == rank)
      break ;
    i++;
  }
  return (vn->cb[i]);
}

void ft_checking(t_env *vn, int rank)
{
  int i;

  i = 0;
  while (i <= vn->len - 1)
  {
    if (vn->res[i] == rank)
      break ;
    i++;
  }
  vn->cb[i] = 1;
}

void ft_unchecking(t_env *vn, int rank)
{
  int i;

  i = 0;
  while (i <= vn->len - 1)
  {
    if (vn->res[i] == rank)
      break ;
    i++;
  }
  vn->cb[i] = 0;
}

void ft_align_up_down(t_env *vn, int times, t_ps *ps, int cmd)
{
  while(times >= 0)
  {
    if (cmd)
    {
      ps->ins = ft_strjoin_customed(ps->ins, "rra\n");
      rra(vn->a);
    }
    else
    {
      ps->ins = ft_strjoin_customed(ps->ins, "ra\n");
      ra(vn->a);
    }
    times--;
  }
}

void ft_align_a(t_env *vn, t_ps *ps)
{
  int pos_min;
  int pos_max;
  int tmp;
  int tmp2;
  int i;

  pos_min = rank_to_pos_a(vn, 0);
  pos_max = rank_to_pos_a(vn, vn->len - 1);
  if (pos_min + 1 < vn->len - 1 - pos_max)
    ft_align_up_down(vn, pos_min, ps, 1);
  else
    ft_align_up_down(vn, vn->len - 1 - pos_max, ps, 0);
}

void push_swap(t_env *vn, t_ps *ps)
{
  int pos;
  int i;
  int tmp;
  int tmp2;
  int j;

  ps->head = vn->len - 1;
  ft_checking(vn, ps->head);
  while (ft_check(vn, vn->cb))
  {
    j = ps->head - 1;
    while (ft_is_check(vn, j) && j >= 0)
      j--;
    if (j == 0 && ft_is_check(vn, j))
      break ;
    ps->moves = calc_elem_to_suit_pos(vn, j, ps);
    ps->curr = j;
    i = ps->head - 1;
    while (i >= 0)
    {
      if (rank_to_pos_a(vn, i) == rank_to_pos_a(vn, i + 1) + 1)
        ft_checking(vn, i);
      i--;
    }
    i = ps->head - 1;
    while (i >= 0)
    {
      if (rank_to_pos_a(vn, i) == rank_to_pos_a(vn, i + 1) + 1)
        ft_checking(vn, i);
      if (!ft_is_check(vn, i))
      {
        tmp = calc_elem_to_suit_pos(vn, i, ps);
        if (ps->moves < tmp)
        {
          ps->moves = tmp;
          ps->curr = i;
        }
      }
      i--;
    }
    i = ps->head - 1;
    while (i >= 0)
    {
      tmp2 = rank_to_pos_a(vn, i);
      if (tmp2 == 0 || tmp2 == vn->len - 1)
      {
        i--;
        continue ;
      }
      if (tmp2 != rank_to_pos_a(vn, i + 1) + 1
        && tmp2 != rank_to_pos_a(vn, i - 1))
        ft_unchecking(vn, i);
      i--;
    }
    //printf("\n--(%d)--\n", ps->curr);
    put_elem_to_suit_pos(vn, ps->curr, ps);
    ft_checking(vn, ps->curr);
  }
  ft_align_a(vn, ps);
  printf("%s", ps->ins);
}
