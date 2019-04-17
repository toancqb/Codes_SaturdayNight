#include "../../includes/ft_lib_push_swap.h"
#include "../stack/st_lib_stack.h"

void ft_error()
{
  ft_putstr("Error\n");
  exit(-1);
}

void ft_ok()
{
  ft_putstr("OK\n");
  exit(1);
}

void ft_ko()
{
  ft_putstr("KO\n");
  exit(0);
}

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

void ft_command(char *line, t_st *a, t_st *b)
{
  ft_putstr(line); ft_putchar('\n');

  if (!ft_strcmp(line, "sa"))
    sa(a);
  if (!ft_strcmp(line, "sb"))
    sb(b);
  if (!ft_strcmp(line, "ss"))
    ss(a, b);
  if (!ft_strcmp(line, "pa"))
    pa(&a, &b);
  if (!ft_strcmp(line, "pb"))
    pb(&a, &b);
  if (!ft_strcmp(line, "ra"))
    ra(a);
  if (!ft_strcmp(line, "rb"))
    rb(b);
  if (!ft_strcmp(line, "rr"))
    rr(a, b);
  if (!ft_strcmp(line, "rra"))
    rra(a);
  if (!ft_strcmp(line, "rrb"))
    rrb(b);
  if (!ft_strcmp(line, "rrr"))
    rrr(a, b);
  //else
  //  ft_error();
}

void f_p(int val)
{
  printf("(%d)\n", val);
}

void check_st(t_st *a, int len)
{
  t_elem *tmp;

  printf("\n--%d--%d\n", st_nb_elem(a), len);
  if (st_nb_elem(a) == len)
  {
    tmp = a->st_l;
    while (tmp->prev != NULL)
    {
      //printf("\n(%d < %d)\n", tmp->v, tmp->prev->v);
      if (tmp->v > tmp->prev->v)
        ft_ko();
      tmp = tmp->prev;
    }
    ft_ok();
  }
  else
    ft_ko();
}

int main(int argc, char *argv[])
{
  t_st *a;
  t_st *b;
  char *line;
  int *input;
  ssize_t size;
  int len;

  len = 0;
  input = NULL;
  a = st_init_stack();
  b = st_init_stack();
  input = ft_process_input(argc, argv, &len);
  ft_init_checker(a, b, input, len);
  free(input);
  while ((size = get_next_line(STDIN_DEFAULT, &line)) > 0)
  {
    ft_command(line, a, b);
    free(line);
  }
  if (size == -1)
  {
    ft_putstr("zz\n");
    ft_error();
  }
  st_f_inverse_val(a, &f_p);
  check_st(a, len);
  st_free_stack(&a);
  st_free_stack(&b);
  return (0);
}
