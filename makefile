# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpascal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 22:47:15 by jpascal           #+#    #+#              #
#    Updated: 2017/05/22 19:18:27 by jpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME2 = checker

SRC_ALL_PATH = ./

SRC_PSHSWP_NAME =	push_swap.c \
					sort.c \
					parseur_push_swap.c \
					swap_a_b.c \
					push_a_b.c \
					rotate_a_b.c \
					reverse_rotate_a_b.c \
					tools.c \
					tools2.c \
					mini_push_swap.c

OBJ_PSHSWP_NAME = $(SRC_PSHSWP_NAME:.c=.o)

SRC_CHECK_NAME =	checker.c \
					parseur_push_swap.c \
					swap_a_b.c \
					push_a_b.c \
					rotate_a_b.c \
					reverse_rotate_a_b.c \
					tools.c \
					tools2.c


OBJ_CHECK_NAME = $(SRC_CHECK_NAME:.c=.o)

LIB_NAME = libft.a

LIB_PATH =  libft/

OBJ_PSHSWP_PATH = 	./pshswp/

OBJ_CHECK_PATH = ./check/

CC = gcc

W_FLAGS = -Werror -Wall -Wextra -g

I_FLAGS = -I includes

SRC_PSHSWP = $(addprefix $(SRC_ALL_PATH),$(SRC_PSHSWP_NAME))
OBJ_PSHSWP = $(addprefix $(OBJ_PSHSWP_PATH),$(OBJ_PSHSWP_NAME))
SRC_CHECK = $(addprefix $(SRC_ALL_PATH),$(SRC_CHECK_NAME))
OBJ_CHECK = $(addprefix $(OBJ_CHECK_PATH),$(OBJ_CHECK_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ_PSHSWP_NAME)
	@make -C $(LIB_PATH)
	@mkdir $(OBJ_PSHSWP_PATH) 2> /dev/null || true
	@$(CC) -c $(SRC_PSHSWP) $(I_FLAGS) $(W_FLAGS)
	@mv $(OBJ_PSHSWP_NAME) $(OBJ_PSHSWP_PATH)
	@$(CC) -o $(NAME) $(OBJ_PSHSWP) $(LIB)

$(NAME2): $(OBJ_CHECK_NAME)
	@mkdir $(OBJ_CHECK_PATH) 2> /dev/null || true
	@$(CC) -c $(SRC_CHECK) $(I_FLAGS) $(W_FLAGS)
	@mv $(OBJ_CHECK_NAME) $(OBJ_CHECK_PATH)
	@$(CC) -o $(NAME2) $(OBJ_CHECK) $(LIB)

clean:
	@make clean -C $(LIB_PATH)
	@rm -f $(OBJ_PSHSWP)
	@rm -f $(OBJ_CHECK)
	@rmdir $(OBJ_PSHSWP_PATH) 2> /dev/null || true
	@rmdir $(OBJ_CHECK_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME) $(NAME2) 

re: fclean all