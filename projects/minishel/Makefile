# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:26:21 by decordel          #+#    #+#              #
#    Updated: 2022/04/19 19:54:26 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

S		= src/
O		= obj/

LIBFT	= libft/libft.a

SRCS		=	$S${NAME}.c	$Spars.c $Sexe.c\
				$Sft_cmd.c	$Sft_sig.c

OBJS		= ${SRCS:$S%.c=$O%.o}

INCS		= inc/${NAME}.h

CC		= gcc

FLAGS	= -Wall -Wextra -Werror -g
LFLAGS		= -L libft/ -lft -lreadline -ltermcap -L/Users/${USER}/.brew/opt/readline/lib/

all		: ${NAME}

${NAME}	: ${INCS} ${LIBFT} ${O} ${OBJS}
	${CC} ${FLAGS} ${LFLAGS} ${OBJS} -o ${NAME}

${O}	:
	mkdir obj

$O%.o		: $S%.c ${INCS}
	${CC} ${FLAGS} -c $< -o $@

${LIBFT}	:
	make -C libft/

clean	:
	@rm -rf ${O}
	@make clean -C libft/

fclean	:
	rm -rf ${NAME}
	rm -rf ${O}
	@make fclean -C libft/

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
