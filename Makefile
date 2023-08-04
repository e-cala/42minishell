# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 17:25:20 by ecabanas          #+#    #+#              #
#    Updated: 2023/08/04 18:41:03 by ecabanas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		minishell
HEADER		=		includes/minishell.h

SRC			=		src
OBJ			=		obj
SRCS		=		$(wildcard $(SRC)/*.c)
OBJS		=		$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
DEPS		=		$(addsuffix .d, $(basename $(SRCS)))

LIBFT		=		-L ./lib/libft -lft
LREADLINE	=		-L /Users/ecabanas/.brew/Cellar/readline/8.2.1/lib
IREADLINE	=		-I /Users/ecabanas/.brew/Cellar/readline/8.2.1/lib/libreadline.dylib

CC			=		gcc
CFLAGS		=		-Wall -Wextra -Werror -MMD

RM			=		rm -rf

######################################################################

all: $(NAME)

libft:
	make -C lib/libft

$(NAME):  libft $(OBJS)
	$(CC) $(CFLAGS) $(LREADLINE) $(LIBFT) $(IREADLINE) -lreadline $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir $@

clean:
	make -C lib/libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C lib/libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
