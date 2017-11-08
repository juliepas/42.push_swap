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

# EXECUTABLES

NAME 			= push_swap

NAME2 			= checker

# PATHS

SRCS_PATH 		= ./src/

INC_PATH		= ./includes/

OBJ_PATH		= ./obj/

OBJ_PSHSWP_PATH = $(OBJ_PATH)pshswp/

OBJ_CHECK_PATH 	= $(OBJ_PATH)checker/

LIB_PATH 		=  ./libft/

#SOURCES

SRC_PSHSWP_NAME =	$(SRCS_PATH)push_swap.c \
					$(SRCS_PATH)sort.c \
					$(SRCS_PATH)parseur_push_swap.c \
					$(SRCS_PATH)swap_a_b.c \
					$(SRCS_PATH)push_a_b.c \
					$(SRCS_PATH)rotate_a_b.c \
					$(SRCS_PATH)reverse_rotate_a_b.c \
					$(SRCS_PATH)tools.c \
					$(SRCS_PATH)tools2.c \
					$(SRCS_PATH)mini_push_swap.c

SRC_CHECK_NAME 	=	$(SRCS_PATH)checker.c \
					$(SRCS_PATH)parseur_push_swap.c \
					$(SRCS_PATH)swap_a_b.c \
					$(SRCS_PATH)push_a_b.c \
					$(SRCS_PATH)rotate_a_b.c \
					$(SRCS_PATH)reverse_rotate_a_b.c \
					$(SRCS_PATH)tools.c \
					$(SRCS_PATH)tools2.c

LIB				= libft/libft.a

# LIB_NAME 		= libft.a

#OBJECTS

OBJ_PSHSWP_NAME = $(SRC_PSHSWP_NAME:$(SRCS_PATH)%.c=$(OBJ_PATH)pshswp/%.o)

OBJ_CHECK_NAME 	= $(SRC_CHECK_NAME:$(SRCS_PATH)%.c=$(OBJ_PATH)checker/%.o)

# COMPILATION

CC 				= clang

W_FLAGS 		= -Werror -Wall -Wextra -g3

I_FLAGS 		= -I$(INC_PATH)

#COLORS

GREEN			= "\033[0;32m"
EOC				= "\033[0;0m"
RED				= "\033[0;31m"

# COMMANDS

.PHONY: all clean fclean re
.SILENT:

all: checkpath $(NAME) $(NAME2)

$(OBJ_PSHSWP_PATH)%.o : $(SRCS_PATH)%.c
	$(CC) $(W_FLAGS) -c $< -o $@ $(I_FLAGS)
	echo "["$(GREEN)"√"$(EOC)"]" $@

$(OBJ_CHECK_PATH)%.o : $(SRCS_PATH)%.c
	$(CC) $(W_FLAGS) -c $< -o $@ $(I_FLAGS)
	echo "["$(GREEN)"√"$(EOC)"]" $@

checkpath:
	test -d $(OBJ_PATH) || mkdir $(OBJ_PATH)
	test -d $(OBJ_PATH)pshswp || mkdir $(OBJ_PATH)pshswp
	test -d $(OBJ_PATH)checker || mkdir $(OBJ_PATH)checker

$(NAME): $(OBJ_PSHSWP_NAME)
	make -C $(LIB_PATH)
	$(CC) $(W_FLAGS) -o $(NAME) $(OBJ_PSHSWP_NAME) $(LIB) $(I_FLAGS)
	echo $(GREEN)"PUSHSWAP SUCCESSFULLY COMPILED"$(EOC)

$(NAME2): $(OBJ_CHECK_NAME)
	$(CC) $(W_FLAGS) -o $(NAME2) $(OBJ_CHECK_NAME) $(LIB) $(I_FLAGS)
	echo $(GREEN)"CHECKER SUCCESSFULLY COMPILED"$(EOC)

clean:
	make clean -C $(LIB_PATH)
	rm -rf $(OBJ_PATH)
	echo $(RED)"ALL OBJECTS DELETED"$(EOC)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -rf $(NAME) 
	rm -rf $(NAME2)
	echo $(RED)"EXEC DELETED"$(EOC) 

re: fclean 
	@$(MAKE) all