# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:26:21 by decordel          #+#    #+#              #
#    Updated: 2022/03/04 23:44:08 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus

S		= src/
O		= obj/

SRCS		=	$Smain.c\
					$Sphilo.c	$Sphilo_activity.c $Sforks.c\
					$Sft_atoi.c	$Svalid.c	$Sft_error.c\
					$Stime.c	$Smonitoring.c

OBJS		= ${SRCS:$S%.c=$O%.o}

INCS		= inc/${NAME}.h

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

all		: ${NAME}

${NAME}	: ${INCS} ${O} ${OBJS}
	${CC} -lpthread ${FLAGS} ${OBJS} -o ${NAME}

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

ARGS	= 200 410 200 200

git		:
	git add .
	git commit -m "${MESS}"
	git push

do		:
	make all
	./${NAME} ${ARGS}

time	:
	make all
	time ./${NAME} ${ARGS}

leaks	:
	make all
	leaks -atExit -- ./${NAME} ${ARGS}

debug	:
	make all
	lldb -- ./${NAME} ${ARGS}

norm	:
	norminette | grep Er

#! debug ---------------------------------

.PHONY	: all clean fclean re git do leaks debug norm time
