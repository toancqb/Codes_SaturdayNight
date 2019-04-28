# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 21:23:07 by qtran             #+#    #+#              #
#    Updated: 2019/04/28 21:23:09 by qtran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker
CC = gcc
FLAGS = -Wall -Werror -Wextra
DIR_SRC = src
LIBFT = libft
DIR_CH = $(DIR_SRC)/checker
DIR_PS = $(DIR_SRC)/push_swap
DIR_OP = $(DIR_SRC)/operation
DIR_ST = $(DIR_SRC)/stack

S_CH = checker.c

S_OP =	p_ab.c\
					rr_ab.c\
					rrr_ab.c\
					ss_ab.c\
					tool.c\
					tools.c\
					toolss.c\
					ft_init_ps.c

S_ST =	st_f_inverse_val.c\
					st_f_val.c\
					st_free_stack.c\
					st_init_elem.c\
					st_init_stack.c\
					st_nb_elem.c\
					st_pop.c\
					st_push.c

S_PS =	push_swap.c\
					ft_a_to_b.c\
					ft_a_to_top_minus.c\
					ft_a_to_top.c\
					ft_align_a.c\
					ft_b_to_a.c\
					ft_calc.c\
					ft_funcs_1.c\
					ft_funcs_2.c\
					ft_funcs_3.c\
					ft_ps_3.c\
					ft_ps_5.c\
					ft_select.c

SRC_CH = $(addprefix $(DIR_CH)/,$(S_CH))
SRC_OP = $(addprefix $(DIR_OP)/,$(S_OP))
SRC_ST = $(addprefix $(DIR_ST)/,$(S_ST))
SRC_PS = $(addprefix $(DIR_PS)/,$(S_PS))

OBJ_CH = $(S_CH:.c=.o)
OBJ_OP = $(S_OP:.c=.o)
OBJ_ST = $(S_ST:.c=.o)
OBJ_PS = $(S_PS:.c=.o)

all: $(LIBFT) $(NAME_CH) $(NAME_PS)

$(LIBFT):
	cd $(LIBFT)
	make re
	cd ..

$(NAME_CH): $(OBJ_ST) $(OBJ_OP)
	@$(CC) $(FLAGS) $(SRC_CH) -o $(OBJ_ST) $(OBJ_OP) $(LIBFT)/libft.a -o $(NAME_CH)

$(NAME_PS): $(OBJ_ST) $(OBJ_OP)
	@$(CC) $(FLAGS) $(SRC_PS) -o $(OBJ_ST) $(OBJ_OP) $(LIBFT)/libft.a -o $(NAME_PS)

$(OBJ_ST):
	@$(CC) $(FLAGS) -c $(SRC_ST)

$(OBJ_OP):
	@$(CC) $(FLAGS) -c $(SRC_OP)

#$(OBJ_CH):
#	$(CC) $(FLAGS) -c $(SRC_CH)

#$(OBJ_PS):
#	$(CC) $(FLAGS) -c $(SRC_PS)

clean:
	@rm -f $(OBJ_CH) $(OBJ_PS) $(OBJ_OP) $(OBJ_ST)

fclean: clean
	@rm -f $(NAME_CH) $(NAME_PS)

re: fclean all

.PHONY: fclean re all clean
