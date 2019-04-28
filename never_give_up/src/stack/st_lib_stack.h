/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_lib_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:29:49 by qtran             #+#    #+#             */
/*   Updated: 2019/04/28 18:13:57 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ST_LIB_STACK_H
# define ST_LIB_STACK_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_elem
{
	int				v;
	int				r;
	struct s_elem	*next;
	struct s_elem	*prev;
}				t_elem;

typedef struct	s_st
{
	t_elem *st_f;
	t_elem *st_l;
}				t_st;

t_elem			*st_init_elem(int val, int rank);
t_st			*st_init_stack(void);

int				st_nb_elem(t_st *st);

void			st_free_elem(t_elem **e);
void			st_free_stack(t_st **st);

void			st_push(t_st **st, t_elem *elem);
t_elem			*st_pop(t_st **st);

void			st_f_val(t_st *st, void (*f)(int val));
void			st_f_inverse_val(t_st *st, void (*f)(int val), int c);

void			st_free_2stacks(t_st **a, t_st **b);
void			st_init_2stacks(t_st **a, t_st **b);

#endif
