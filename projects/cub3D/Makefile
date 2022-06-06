# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:26:21 by decordel          #+#    #+#              #
#    Updated: 2022/06/06 18:24:30 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

S			=	src/
O			=	obj
D			=	deps
I			=	incs/

SRCS		=	$S${NAME}.c

OBJS		= ${SRCS:$S%.c=$O/%.o}

INCS		= inc/${NAME}.h

LIBFT		= libft/libft.a
MLXLIB		= ../libmlx.dylib

CC		= gcc

FLAGS		= -g -Wall -Wextra -Werror -Imlx
LFLAGS		= -L libft/ -lft
MLXFLAGS	= -Lminilibx_mms -lmlx -framework OpenGL -framework AppKit

all		: ${NAME}

${NAME}	: ${INCS} ${OBJS} ${LIBFT} | ${MLXLIB}
	${CC} ${FLAGS} ${LFLAGS} ${MLXFLAGS} ${OBJS} -o ${NAME}

# Building objective files (*.o)
$O			:
	@mkdir $@

$O/%.o		: $S%.c ${INCS} | $O
	${CC} ${FLAGS} -c $< -o $@

${LIBFT}	:
	@make all -C libft/
${MLXLIB}	:
	@make all -C minilibx_mms/

clean	:
	rm -rf ${OBJS}
	make clean -C libft/

fclean	: clean
	rm -rf ${NAME}
	make fclean -C libft/

re		: fclean all

#! debug ---------------------------------

MESS	= fix

ARGS	= ""

git		:
	git add .
	git commit -m "${MESS}"
	git push

do		:
	make all
	./${NAME} ${ARGS}

sh		:
	make all
	./test.sh ${ARGS}

leaks	:
	make all
	leaks -atExit -- ./${NAME} ${ARGS}

debug	:
	make all
	lldb -- ./${NAME} ${ARGS}

norm	:
	norminette | grep Er

#! debug ---------------------------------
