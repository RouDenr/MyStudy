# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 18:18:03 by decordel          #+#    #+#              #
#    Updated: 2021/12/14 18:30:30 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= main.c

OBJS	= ${SRCS:%.c=%.o}

INCS		= inc/push_swap.h inc/libft.h

LIB		= libft/libft.a

FLAGS	= -g -Wall -Wextra -Wextra
LFLAGS	= -L libft/ -lft

all		: ${NAME}

${NAME}	: ${INCS} ${LIB} ${OBJS}
	gcc ${FLAGS} ${LFLAGS} ${OBJS} -o ${NAME}

%.o		: ${INCS} %.c
	gcc ${FLAGS} -c $< -o $@

${LIB}	:
	make all -C libft/

clean	:
	@rm -rf ${OBJS}
	@make clean -C libft/

fclean	: clean
	rm -rf ${NAME}
	@make fclean -C libft/

re		: fclean all

.PHONY	: all clean fclean re
