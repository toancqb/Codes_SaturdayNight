#include "../../includes/ft_lib_push_swap.h"

void ft_checking_pos(t_env *vn, int pos)
{
  int rank;

  rank = val_to_rank(vn, vn->a->tab[in(vn->a->bot + pos)]);
  ft_checking(vn, rank);
}

int ft_calc_head(t_env *vn, int rank)
{
  int pos;
  int bot;
  int count;
  int tmp;

  count = 1;
  bot = vn->a->bot;
  tmp = rank_to_pos_a(vn, rank);
  pos = tmp - 1;
  while (pos >= 0)
  {
    if (vn->a->tab[in(bot + pos)] > vn->a->tab[in(bot + tmp)])
    {
      count++;
      tmp = pos;
    }
    pos--;
  }
  return (count);
}

void ft_select_to_b(t_env *vn, t_ps *ps)
{
  int i;
  int tmp;
  int pos;
  int bot;

  i = 0;
  bot = vn->a->bot;
  ps->head = i;
  ps->moves = ft_calc_head(vn, ps->head);
  i++;
  while (i < vn->len)
  {
    tmp = ft_calc_head(vn, i);
    if (ps->moves < tmp || (ps->moves == tmp && i < ps->head))
     {
       ps->moves = tmp;
       ps->head = i;
     }
    i++;
  }
  //ft_checking(vn, rank_to_pos_a(vn, ps->head));
  pos = rank_to_pos_a(vn, ps->head);
  ft_checking_pos(vn, pos);
  tmp = pos;
  pos--;
  while (pos >= 0)
  {
    if (vn->a->tab[in(bot + pos)] > vn->a->tab[in(bot + tmp)])
    {
      ft_checking_pos(vn, pos);
      tmp = pos;
    }
    pos--;
  }
}

int ft_is_true(t_env *vn, int val)
{
  int i;

  i = 0;
  while (i <= vn->len - 1)
  {
    if (vn->org[i] == val)
    {
      return (vn->cb[i]);
    }
    i++;
  }
  return (-1);
}

int ft_is_f_in_a(t_env *vn)
{
  int i;
  int len;

  i = 0;
  len = st_nb_elem(vn->a);
  while (i < len)
  {
    if (!ft_is_true(vn, vn->a->tab[in(vn->a->bot + i)]))
      return (1);
    i++;
  }
  return (0);
}

void ft_a_to_b(t_env *vn, t_ps *ps)
{
  while (ft_is_f_in_a(vn))
  {
    if (!ft_is_true(vn, vn->a->tab[in(vn->a->top)]))
    {
      ps->ins = ft_strjoin_customed(ps->ins, "pb\n");
      pb(vn->b, vn->a);
    }
    else
    {
      ps->ins = ft_strjoin_customed(ps->ins, "ra\n");
      ra(vn->a);
    }
  }
}

int ft_is_done(t_env *vn)
{
  int len;
  int rank;
  int pos;

  rank = 0;
  len = st_nb_elem(vn->a);
  while (rank < len)
  {
    pos = rank_to_pos_a(vn, rank);
    if (rank != pos)
      return (0);
    rank++;
  }
  return (1);
}

void ft_apply(t_env *vn, t_ps *ps)
{
  char **tab;
  int i;

  tab = ft_strsplit(ps->ins, '\n');
  i = 0;
  while (tab[i] != NULL)
  {
    if (!ft_strcmp(tab[i], "pb"))
      pb(vn->b, vn->a);
    if (!ft_strcmp(tab[i], "pa"))
      pa(vn->a, vn->b);
    if (!ft_strcmp(tab[i], "sa"))
      sa(vn->a);
    if (!ft_strcmp(tab[i], "sb"))
      sb(vn->b);
    if (!ft_strcmp(tab[i], "ss"))
      ss(vn->a, vn->b);
    if (!ft_strcmp(tab[i], "ra"))
      ra(vn->a);
    if (!ft_strcmp(tab[i], "rb"))
      rb(vn->b);
    if (!ft_strcmp(tab[i], "rr"))
      rr(vn->a, vn->b);
    if (!ft_strcmp(tab[i], "rra"))
      rra(vn->a);
    if (!ft_strcmp(tab[i], "rrb"))
      rrb(vn->b);
    if (!ft_strcmp(tab[i], "rrr"))
      rrr(vn->a, vn->b);
    i++;
  }
}

void ft_common(t_ps *ps)
{
  int i;
  int j;
  char **ta = NULL;
  char **tb = NULL;

  ta = ft_strsplit(ps->ins_a, '\n');
  tb = ft_strsplit(ps->ins_b, '\n');
  i = 0;
  j = 0;

  while (ta[i] != NULL)
  {
    if (tb[j] != NULL && !ft_strcmp(ta[i], "ra") && !ft_strcmp(tb[j], "rb"))
    {
      ps->ins = ft_strjoin_customed(ps->ins, "rr\n");
      i++;
      if (tb[j] != NULL)
        j++;
      continue ;
    }
    else if (tb[j] != NULL && !ft_strcmp(ta[i], "rra")
    && !ft_strcmp(tb[j], "rrb"))
    {
      ps->ins = ft_strjoin_customed(ps->ins, "rrr\n");
      i++;
      if (tb[j] != NULL)
        j++;
      continue ;
    }
    ps->ins = ft_strjoin_customed(ps->ins, ta[i]);
    ps->ins = ft_strjoin_customed(ps->ins, "\n");
    i++;
  }
  while (tb[j] != NULL)
  {
    ps->ins = ft_strjoin_customed(ps->ins, tb[j]);
    ps->ins = ft_strjoin_customed(ps->ins, "\n");
    j++;
  }
  /*while (ta[i])
  {
    ps->ins = ft_strjoin_customed(ps->ins, ta[i]);
    //ps->ins = ft_strjoin_customed(ps->ins, "\n");
    i++;
  }
  ps->ins = ft_strjoin_customed(ps->ins, "\n");
  while (tb[j])
  {
    ps->ins = ft_strjoin_customed(ps->ins, tb[j]);
    //ps->ins = ft_strjoin_customed(ps->ins, "\n");
    j++;
  }*/
}

char *ft_ins(char *ins)
{
  char **tab;
  int i;
  int j;
  char *str = NULL;

  tab = ft_strsplit(ins, '\n');
  i = 0;
  j = 1;
  while (tab[j] != NULL)
  {
    if (!ft_strcmp(tab[i], "ra") && !ft_strcmp(tab[j], "rb"))
      str = ft_strjoin_customed(str, "rr\n");
    else if (!ft_strcmp(tab[i], "rb") && !ft_strcmp(tab[j], "ra"))
      str = ft_strjoin_customed(str, "rr\n");
    else if (!ft_strcmp(tab[i], "rra") && !ft_strcmp(tab[j], "rrb"))
      str = ft_strjoin_customed(str, "rrr\n");
    else if (!ft_strcmp(tab[i], "rrb") && !ft_strcmp(tab[j], "rra"))
      str = ft_strjoin_customed(str, "rrr\n");
    else
    {
      str = ft_strjoin_customed(str, tab[i]);
      str = ft_strjoin_customed(str, "\n");
      i++; j++;
      continue ;
    }
    i+=2; j+=2;
  }
  return (str);
}

void push_swap2(t_env *vn, t_ps *ps)
{
    char *str = NULL;

    ft_select_to_b(vn, ps);
    ft_a_to_b(vn, ps);
    ft_select_to_a(vn, ps);
    ft_align_a(vn, ps);

    str = ft_ins(ps->ins);

    printf("%s", str);
}
