#include "../../includes/ft_lib_push_swap.h"

int *ft_process_input(int argc, char **argv, int *len)
{
  char **tab;
  int i;
  int j;
  int *input;

  *len = 0;
  if (argc >= 2)
  {
    tab = ft_strsplit(argv[1], ' ');
    while (tab[*len] != NULL)
      (*len)++;
    input = (int*)malloc(sizeof(int) * (*len));
    i = 0;
    j = *len - 1;
    while (j >= 0 && tab[i])
    {
      input[j] = (int)ft_atoi(tab[i]);
      j--;
      free(tab[i]);
      i++;
    }
    free(tab);
    return (input);
  }
  else
    ft_error();
  return (NULL);
}

void ft_init_checker(t_st *a, t_st *b, int *input, int len)
{
  int i;
  int tmp;

  i = 0;
  while (i < len)
  {
    tmp = input[i];
    st_push(&a, st_init_elem(tmp, 0));
    i++;
  }
  if (st_nb_elem(a))
    return ;
}

int main(int argc, char *argv[])
{
  t_st *a;
  t_st *b;
  int *input;
  int len;

  len = 0;
  input = NULL;
  a = st_init_stack();
  b = st_init_stack();
  input = ft_process_input(argc, argv, &len);
  ft_init_checker(a, b, input, len);
  free(input);
  
}
