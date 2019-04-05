#include "../../includes/ft_lib_push_swap.h"

/*int calc_upper_b(t_env *vn, int pos, int len, t_ps *ps)
{
  int count;

  count = 0;
  while (pos < len - 1)
  {
    count++;
    pos++;
  }
  return (count);
}

int calc_lower_b(t_env *vn, int pos, int len, t_ps *ps)
{
  int count;

  count = 0;
  while (pos >= 0)
  {
    count++;
    pos--;
  }
  return (count);
}*/

int calc_pos_to_top_a(t_env *vn, int rank)
{
  int place;
  int len;
  int pos;

  len = st_nb_elem(vn->a);
  while (rank_to_pos_a(vn, rank) == -1)
  {
    if (rank == vn->len - 1)
      break ;
    rank++;
  }
  pos = rank_to_pos_a(vn, rank);
  place = place_elem(vn->a, pos);
  if (place == 0)
    return (0);
  else if (place == 1)
    return (len - 1 - pos);
  else if (place == 3)
    return (1);
  else
    return (pos + 1);

}

int calc_elem_to_suit_pos_from_b(t_env *vn, int pos)
{
  int place;
  int len;
  int rank;
  int pos_to_top;
  t_st *b;

  b = vn->b;
  rank = val_to_rank(vn, b->tab[in(b->bot + pos)]);
  len = b->top - b->bot + 1;
  place = place_elem(b, pos);
  if (rank + 1 == vn->len - 1)
    pos_to_top = calc_pos_to_top_a(vn, 0);
  else
  {
    rank++;
    while (rank_to_pos_a(vn, rank) == -1)
      rank++;
    pos_to_top = calc_pos_to_top_a(vn, rank);
  }
  if (place == 0)
    return (1 + pos_to_top);
  else if (place == 1)
    return (len - pos + pos_to_top);
  else if (place == 3)
    return (2 + pos_to_top);
  else
    return (pos + 1 + pos_to_top);
}

void ft_select_to_a(t_env *vn, t_ps *ps)
{
  int pos;
  int rank;
  int ins_min;
  int tmp;
  int curr;
  t_st *b;

  b = vn->b;
  while (b->top - b->bot + 1 != 0)
  {
    pos = b->top - b->bot;
    ins_min = calc_elem_to_suit_pos_from_b(vn, pos);
    curr = pos;
    pos--;
    while (pos >= 0)
    {
      tmp = calc_elem_to_suit_pos_from_b(vn, pos);
      if (ins_min > tmp)
      {
        curr = pos;
        ins_min = tmp;
      }
      pos--;
    }
    printf("--(%d)--", curr);
    rank = val_to_rank(vn, b->tab[in(b->bot + curr)]);
    if (rank < vn->len - 1)
    {
      rank++;
      while (rank_to_pos_a(vn, rank) == -1)
      {
        rank++;
      }
      if (rank_to_pos_a(vn, rank) != st_nb_elem(vn->a) - 1)
        pos_to_top(vn, rank_to_pos_a(vn, rank), ps);
    }
    else if (rank == vn->len - 1)
    {
      rank = 0;
      while (rank_to_pos_a(vn, rank) == -1)
        rank++;
      pos_to_top(vn, rank_to_pos_a(vn, rank), ps);
    }
    push_b_to_a(vn, curr, ps);
    /*ft_common(ps);
    ft_apply(vn, ps);
    free(ps->ins_a); ps->ins_a = ft_strnew(1);
    free(ps->ins_b); ps->ins_b = ft_strnew(1);*/
  }
}
