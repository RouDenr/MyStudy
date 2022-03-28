# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:28:03 by decordel          #+#    #+#              #
#    Updated: 2021/12/06 16:13:31 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex.out

SRCS		=	pipex.c				src/pip_utils.c\
				src/get_next_line.c	src/get_next_line_utils.c

INCLUDES	= inc/pipex.h inc/libft.h

LIB			= libft/libft.a

OBJS		= ${SRCS:%.c=%.o}
OBJS_B		= ${SRCS_B:%.c=%.o}

FLAGS		= -g -Wall -Wextra -Werror
LFLAGS		= -L libft/ -lft

all			: ${NAME}

${NAME}		: ${INCLUDES} ${OBJS} ${LIB}
	gcc ${FLAGS} ${LFLAGS} ${OBJS} -o ${NAME}

%.o			: %.c ${INCLUDES}
	gcc ${FLAGS} -c $< -o $@

${LIB}		:
	make all -C libft/

clean		:
	@rm -rf ${OBJS} ${OBJS_B}
	@make clean -C libft/

fclean		: clean
	@rm -rf ${NAME}
	@make fclean -C libft/

re			: fclean all

.PHONY	: all clean fclean re
