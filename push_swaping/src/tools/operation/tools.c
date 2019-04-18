#include "../../includes/ft_lib_push_swap.h"

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

void f_p(int val)
{
//  printf("(%d)\n", val);
  ft_putchar('(');
  ft_putnbr(val);
  ft_putstr(")\n");
}
