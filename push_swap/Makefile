# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 18:18:03 by decordel          #+#    #+#              #
#    Updated: 2022/01/20 06:38:13 by decordel         ###   ########.fr        #
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

ARGS	= 9 0 13 6 14 10 4 1 12 11 7 8 5 15 3 2 17 18 16

N		= 500 50

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
