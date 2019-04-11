#include "../../includes/ft_lib_push_swap.h"

void pos_upper_b(t_env *vn, int pos, int len, t_ps *ps)
{
  (void)vn;
  (void)ps;
  while (pos < len - 1)
  {
    //ps->ins = ft_strjoin_customed(ps->ins, "rb\n");
    ft_putstr("rb\n");
    rb(vn->b);
    pos++;
  }
  //ps->ins = ft_strjoin_customed(ps->ins, "pa\n");
  ft_putstr("pa\n");
  pa(vn->a, vn->b);
}

void pos_lower_b(t_env *vn, int pos, int len, t_ps *ps)
{
  (void)len; (void)vn;
  (void)ps;
  while (pos >= 0)
  {
    //ps->ins = ft_strjoin_customed(ps->ins, "rrb\n");
    ft_putstr("rrb\n");
    rrb(vn->b);
    pos--;
  }
  //ps->ins = ft_strjoin_customed(ps->ins, "pa\n");
  ft_putstr("pa\n");
  pa(vn->a, vn->b);
}

int push_b_to_a(t_env *vn, int pos, t_ps *ps)
{
  int place;
  int len;

  len = vn->b->top - vn->b->bot + 1;
  place = place_elem(vn->b, pos);
  if (place == 0)
  {
    //ps->ins = ft_strjoin_customed(ps->ins, "pa\n");
    ft_putstr("pa\n");
    pa(vn->a, vn->b);
  }
  else if (place == 1)
    pos_upper_b(vn, pos, len, ps);
  else if(place == 3)
  {
    //ps->ins = ft_strjoin_customed(ps->ins, "rrb\npa\n");
    ft_putstr("rrb\npa\n");
    rrb(vn->b);
    pa(vn->a, vn->b);
  }
  else
    pos_lower_b(vn, pos, len, ps);
  return (0);
}
