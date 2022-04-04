# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:26:21 by decordel          #+#    #+#              #
#    Updated: 2022/04/04 19:45:57 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

S		= src/
O		= obj/

SRCS		=	$S${NAME}.c	$Spars.c $Sexe.c

OBJS		= ${SRCS:$S%.c=$O%.o}

INCS		= inc/${NAME}.h

CC		= gcc

FLAGS	= -Wall -Wextra -Werror
LFLAGS		= -L libft/ -lft -lreadline -ltermcap -L/Users/${USER}/.brew/opt/readline/lib/

all		: ${NAME}

${NAME}	: ${INCS} ${O} ${OBJS}
	${CC} ${FLAGS} ${LFLAGS} ${OBJS} -o ${NAME}

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

do_unset		:
	make all
	unset PATH
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
