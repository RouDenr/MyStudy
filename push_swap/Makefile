# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 18:18:03 by decordel          #+#    #+#              #
#    Updated: 2022/01/24 21:55:27 by decordel         ###   ########.fr        #
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

FLAGS	= -g -Wall -Wextra -Werror
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
#! debug ---------------------------------

MESS	= fix

ARGS	= 10 3 41 15 40 43 8 24 34 5 7 33 42 16 49 23 38 45 32 29 30 27 9 26 14 4 37 46 44 6 13 48 25 47 22 35 12 11 21 39 2 0 17 19 18 1 28 31 20 36

S	= 100 1000

git		:
	git add .
	git commit -m "${MESS}"
	git push

do		:
	make all
	./${NAME} ${ARGS}

sh		:
	make all
	./test.sh ${S}

leaks	:
	make all
	leaks -atExit -- ./${NAME} ${ARGS}

debug	:
	make all
	lldb -- ./${NAME} ${ARGS}

norm	:
	norminette | grep Er

#! debug ---------------------------------

.PHONY	: all clean fclean re
