#include "../../includes/ft_lib_push_swap.h"

int calc_upper(t_env *vn, int pos, int len, t_ps *ps)
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

int calc_lower(t_env *vn, int pos, int len, t_ps *ps)
{
  int count;

  count = 0;
  while (pos >= 0)
  {
    count++;
    pos--;
  }
  return (count);
}

int calc_pos_to_top(t_env *vn, int rank, t_ps *ps)
{
  int place;
  int pos;
  int len;

  len = st_nb_elem(vn->a);
  pos = rank_to_pos_a(vn, rank);
  place = place_elem(vn->a, pos);
  if (place == 0)
    return (0);
  else if (place == 1)
    return (calc_upper(vn, pos, len, ps));
  else if (place == 3)
    return (1);
  else
    return (calc_lower(vn, pos, len, ps));

}

int calc_elem_to_suit_pos(t_env *vn, int rank, t_ps *ps)
{
  int place;
  int pos;
  int len;

  len = st_nb_elem(vn->a);
  pos = rank_to_pos_a(vn, rank);
  place = place_elem(vn->a, pos);
  if (place == 0)
    return (1 + calc_pos_to_top(vn, rank + 1, ps));
  else if (place == 1)
    return (len - pos + calc_pos_to_top(vn, rank + 1, ps));
  else if (place == 3)
    return (pos + 1);
  else
    return (pos + 1 + calc_pos_to_top(vn, rank + 1, ps));
}
