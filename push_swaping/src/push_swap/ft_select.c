#include "../../includes/ft_lib_push_swap.h"

void upper(t_env *vn, int pos, int len, t_ps *ps)
{
  (void)vn;
  while (pos < len - 1)
  {
    ps->ins = ft_strjoin_customed(ps->ins, "ra\n");
    ra(vn->a);
    pos++;
  }
}

void lower(t_env *vn, int pos, t_ps *ps)
{
  (void)vn;
  while (pos >= 0)
  {
    ps->ins = ft_strjoin_customed(ps->ins, "rra\n");
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
    upper(vn, pos, len, ps);
  else if(place == 3)
  {
    ps->ins = ft_strjoin_customed(ps->ins, "rra\n");
    rra(vn->a);
  }
  else
    lower(vn, pos, ps);
  return (0);
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

  pos_min = rank_to_pos_a(vn, 0);
  pos_max = rank_to_pos_a(vn, vn->len - 1);
  if (pos_min + 1 < vn->len - 1 - pos_max)
    ft_align_up_down(vn, pos_min, ps, 1);
  else
    ft_align_up_down(vn, vn->len - 1 - pos_max, ps, 0);
}
