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

void pa(t_st **st_a, t_st **st_b);
void pb(t_st **st_a, t_st **st_b);
void sa(t_st *st_a);
void sb(t_st *st_b);
void ss(t_st *st_a, t_st *st_b);

void ra(t_st *st_a);
void rb(t_st *st_b);
void rr(t_st *st_a, t_st *st_b);

void rra(t_st *st_a);
void rrb(t_st *st_b);
void rrr(t_st *st_a, t_st *st_b);

#endif
