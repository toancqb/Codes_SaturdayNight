#include "../../includes/ft_lib_push_swap.h"

int place_elem(t_st *a, int i)
{
  int len;

  len = st_nb_elem(a);
  if (i == len - 1)
    return (0);
  if (i == 0)
    return (3);
  if (i >= len / 2)
    return (1);
  return (2);
}

void pos_upper(t_env *vn, int pos, int len, t_ps *ps)
{
  while (pos < len - 1)
  {
    ps->ins = ft_strjoin_customed(ps->ins, "ra\n");
    ra(vn->a);
    pos++;
  }
  ps->ins = ft_strjoin_customed(ps->ins, "pb\n");
  pb(vn->b, vn->a);
}

void pos_lower(t_env *vn, int pos, int len, t_ps *ps)
{
  (void)len;
  while (pos >= 0)
  {
    ps->ins = ft_strjoin_customed(ps->ins, "rra\n");
    rra(vn->a);
    pos--;
  }
  ps->ins = ft_strjoin_customed(ps->ins, "pb\n");
  pb(vn->b, vn->a);
}

int push_a_to_b(t_env *vn, int pos, t_ps *ps)
{
  int place;
  int len;

  len = st_nb_elem(vn->a);
  place = place_elem(vn->a, pos);
  if (place == 0)
  {
    ps->ins = ft_strjoin_customed(ps->ins, "pb\n");
    pb(vn->b, vn->a);
  }
  else if (place == 1)
    pos_upper(vn, pos, len, ps);
  else if(place == 3)
  {
    ps->ins = ft_strjoin_customed(ps->ins, "rra\npb\n");
    rra(vn->a);
    pb(vn->b, vn->a);
  }
  else
    pos_lower(vn, pos, len, ps);
  return (0);
}
