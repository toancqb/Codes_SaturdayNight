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
  (void)ps;
  while (ft_is_f_in_a(vn))
  {
    if (!ft_is_true(vn, vn->a->tab[in(vn->a->top)]))
    {
      ft_putstr("pb\n");
      pb(vn->b, vn->a);
    }
    else
    {
      ft_putstr("ra\n");
      ra(vn->a);
    }
  }
}


void printf_ps(t_st *st) //
{
  int i;

  if (st_is_empty(st) == 0)
  {
    i = st->top;
    while (i >= st->bot)
    {
      printf("(%d)\n", st->tab[in(i)]);
      i--;
    }
  }
  printf("\n=--=\n");
}

int maxi(int a, int b)
{
  return ((a >= b)? a : b);
}

int ft_calc_longest_inc_subarr(t_env *vn, int index)
{
  int result = 1;
  int *f;

  f = (int*)malloc(sizeof(int) * (index + 1));
  /*for (int i=1; i <= index; i++)
  {
    f[i] = 0;
    for (int j=0; j<i; j++)
    {
      if (vn->org[j] < vn->org[i])
        f[i] = maxi(f[i], f[j] + 1);
    }
    result = maxi(result, f[i]);
  }*/
  for (int i=0; i<=index; i++)
  {
      f[i] = 0;
      for (int j=i-1; j>=0; j--)
      {
        if (vn->org[i] > vn->org[j])
            f[i] = maxi(f[i], f[j]);
      }
      f[i] += 1;
      result = maxi(result, f[i]);
    }

  free(f);
  return (result);
}

int lis(t_env *vn,  int* a, int len ) {
  int *best, i, j, max = 0;
  int *p;

  best = (int*) malloc ( sizeof( int ) * len );
  p = (int*) malloc ( sizeof( int ) * len );
  for ( i = 0; i < len; i++ )
  {
    best[i] = 1;
    p[i] = -1;
  }
  for ( i = 1; i < len; i++ )
  {    for ( j = 0; j < i; j++ )
      {

          if ( a[i] < a[j] && best[i] < best[j] + 1 )
          {
            best[i] = best[j] + 1;
            p[i] = j;
            if(best[max] < best[i])
                  max = i;
           }
       }
  }
  i = max;
  while (1)
  {
    vn->cb[i] = 1;
    i = p[i];
    if (i == -1)
      break ;
  }
  free(best);
  free(p);
  return max;
}

void ft_select_to_b_new(t_env *vn)
{
  lis(vn, vn->org, vn->len);
}

void push_swap(t_env *vn, t_ps *ps)
{
    ft_select_to_b_new(vn);
    ft_a_to_b(vn, ps);
    ft_select_to_a(vn, ps);
    ft_align_a(vn, ps);
}
