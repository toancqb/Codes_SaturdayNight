/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_push_swap.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:41:40 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 14:43:10 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_PUSH_SWAP_H
# define FT_LIB_PUSH_SWAP_H
# include "../libft/libft.h"
# include "../src/stack/st_lib_stack.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define STDIN_DEFAULT 0

typedef struct  s_env
{
  int *input;
  int *select;
  int len;
} t_env;

void pa(t_st **st_a, t_st **st_b);
void pb(t_st **st_a, t_st **st_b);
void sa(t_st *st_a);
void sb(t_st *st_b);
void ss(t_st *st_a, t_st *st_b);

void ra(t_st **st_a);
void rb(t_st **st_b);
void rr(t_st **st_a, t_st **st_b);

void rra(t_st **st_a);
void rrb(t_st **st_b);
void rrr(t_st **st_a, t_st **st_b);

void f_p(int val);
void ft_error();
void ft_ok();
void ft_ko();
void ft_sort_array(int *arr, int len);
int ft_place(t_st *st, int val, int len);
int ft_calc_b_to_a(t_st *a, t_st *b, int *rr);

int *ft_process_input(int argc, char **argv, int *len);
void ft_init_push_swap(t_st *a, int *input, int *select, int len);
void ft_select(int *select, int len);
void ft_a_to_b(t_st **a, t_st **b, int *input, int *select, int len);
void ft_a_to_top(t_st **a, int rank);
void ft_b_to_a(t_st **a, t_st **b);

#endif
