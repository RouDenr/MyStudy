# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 18:18:03 by decordel          #+#    #+#              #
#    Updated: 2022/01/25 13:52:28 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

NAME_B	= checker

SRCS	= main.c\
			src/stack_com.c		src/stack_info.c	src/get_note.c	src/valid.c\
			src/push.c			src/swap.c			src/rotate.c	src/reverse.c\
			src/sort.c			src/sort_a.c		src/node_info.c

SRCS_B	= bonus/main_bonus.c	bonus/do_com_bonus.c\
			src/stack_com.c		src/stack_info.c	src/get_note.c	src/valid.c\
			src/push.c			src/swap.c			src/rotate.c	src/reverse.c\
			src/sort.c			src/sort_a.c		src/node_info.c

OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}

INCS		= inc/push_swap.h

LIB		= libft/libft.a

CC		= gcc

FLAGS	= -Wall -Wextra -Werror
LFLAGS	= -L libft/ -lft

all		: ${NAME}

${NAME}	: ${INCS} ${OBJS} ${LIB}
	${CC} ${FLAGS} ${LFLAGS} ${OBJS} -o ${NAME}

bonus	: ${NAME_B}

${NAME_B}	: ${INCS} ${OBJS_B} ${LIB}
	${CC} ${FLAGS} ${LFLAGS} ${OBJS_B} -o ${NAME_B}

%.o		: %.c ${INCS}
	${CC} ${FLAGS} -c $< -o $@

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
