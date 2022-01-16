# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 18:18:03 by decordel          #+#    #+#              #
#    Updated: 2022/01/16 22:09:51 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= main.c\
			src/stack_com.c		src/stack_info.c	src/valid.c\
			src/push.c			src/swap.c			src/rotate.c	src/reverse.c\
			src/sort.c

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

ARGS	= 25 79 50 47 95 78 54 42 70 0 19 84 9 60 18 26 43 93 83 61 62 71 3 49 27 89 74 85 5 94 13 10 31 33 96 21 82 17 73 68 35 52 34 100 98 15 24 69 37 90 8 51 44 16 40 46 53 97 76 32 77 81 99 92 6 36 86 57 87 14 45 41 55 75 2 29 65 63 38 28 22 58 11 91 39 48 30 1 20 72 80 23 4 66 88 12 56 67 64 59
git		:
	git add .
	git commit -m "${MESS}"
	git push

do		:
	make all
	./push_swap ${ARGS}

leaks	:
	make all
	leaks -atExit -- ./push_swap ${ARGS}

debug	:
	make all
	lldb -- ./push_swap ${ARGS}
#! debug ---------------------------------
.PHONY	: all clean fclean re git lib debug
