# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 18:18:03 by decordel          #+#    #+#              #
#    Updated: 2022/01/21 21:45:10 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= main.c\
			src/stack_com.c		src/stack_info.c	src/get_note.c	src/valid.c\
			src/push.c			src/swap.c			src/rotate.c	src/reverse.c\
			src/sort.c			src/sort_a.c	src/sort_b.c

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

ARGS	= 38 46 66 50 59 92 57 2 9 64 82 74 87 8 99 37 34 93 48 78 6 45 3 98 19 68 44 90 12 51 31 95 14 71 36 73 21 52 33 42 54 49 80 86 39 35 58 11 69 5 29 75 83 81 16 85 65 94 53 88 4 61 76 70 26 47 0 20 40 22 27 55 77 32 97 30 91 15 62 84 67 10 79 60 63 41 72 89 43 1 18 25 13 7 28 96 17 23 56 24

N		= 50 10

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
#! debug ---------------------------------
.PHONY	: all clean fclean re git lib debug
