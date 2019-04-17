#include "../../includes/ft_lib_push_swap.h"

int maxi(int a, int b)
{
  return ((a >= b)? a : b);
}

int ft_calc_longest_inc_subarr(t_env *vn, int index)
{
  int result = 1;
  int *f;

  f = (int*)malloc(sizeof(int) * (index + 1));
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

void ft_select_to_b(t_env *vn)
{
  lis(vn, vn->org, vn->len);
}
