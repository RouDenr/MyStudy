# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 18:18:03 by decordel          #+#    #+#              #
#    Updated: 2022/01/23 02:57:33 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= main.c\
			src/stack_com.c		src/stack_info.c	src/get_note.c	src/valid.c\
			src/push.c			src/swap.c			src/rotate.c	src/reverse.c\
			src/sort.c			src/sort_a.c	src/sort_b.c		src/node_info.c

OBJS	= ${SRCS:.c=.o}

INCS		= inc/push_swap.h

LIB		= libft/libft.a

CC		= gcc

FLAGS	= -g -Wall -Wextra -Werror
LFLAGS	= -L libft/ -lft

all		: ${NAME}

${NAME}	: ${INCS} ${OBJS} ${LIB}
	${CC} ${FLAGS} ${LFLAGS} ${OBJS} -o ${NAME}

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

ARGS	= 31 11 8 5 37 47 7 14 10 23 22 45 20 26 43 46 32 41 24 3 44 38 25 6 0 19 1 18 48 9 36 17 49 28 16 42 39 34 15 13 2 12 33 35 4 30 40 27 29 21

N		= 500 10

git		:
	git add .
	git commit -m "${MESS}"
	git push

do		:
	make all
	./push_swap ${ARGS}

sh		:
	make all
	./test.sh ${N}

leaks	:
	make all
	leaks -atExit -- ./push_swap ${ARGS}

debug	:
	make all
	lldb -- ./push_swap ${ARGS}

norm	:
	norminette | grep Er

#! debug ---------------------------------
.PHONY	: all clean fclean re git do sh leaks debug
