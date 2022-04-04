# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:26:21 by decordel          #+#    #+#              #
#    Updated: 2022/04/04 13:55:54 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

S		= src/
O		= obj/

SRCS		=	src/${NAME}.c

OBJS		= ${SRCS:$S%.c=$O%.o}

INCS		= inc/${NAME}.h

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

all		: ${NAME}

${NAME}	: ${INCS} ${O} ${OBJS}
	${CC} ${FLAGS} -lreadline -ltermcap -L/Users/${USER}/.brew/opt/readline/lib/ ${OBJS} -o ${NAME}

${O}	:
	mkdir obj

$O%.o		: $S%.c ${INCS}
	${CC} ${FLAGS} -c $< -o $@

clean	:
	@rm -rf ${O}

fclean	:
	rm -rf ${NAME}
	rm -rf ${O}

re		: fclean all

#! debug ---------------------------------

MESS	= fix

ARGS	=

git		:
	git add .
	git commit -m "${MESS}"
	git push

do		:
	make all
	./${NAME} ${ARGS}

#sh		:
#	make all
#	./test.sh ${ARGS}

leaks	:
	make all
	leaks -atExit -- ./${NAME} ${ARGS}

debug	:
	make all
	lldb -- ./${NAME} ${ARGS}

norm	:
	norminette | grep Er

#! debug ---------------------------------

.PHONY	: all clean fclean re git do sh leaks debug norm
