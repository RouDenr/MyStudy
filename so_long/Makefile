# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 22:18:43 by decordel          #+#    #+#              #
#    Updated: 2021/12/14 01:07:40 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_B		= so_long_bonus

SRCS		=	main.c\
				src/map.c	src/check_map.c	src/err.c\
				src/win.c	src/draw.c		src/key_hooks.c\
				src/animation.c		src/enemy.c

SRCS_B		=	main.c\
				src/map.c			src/check_map_b.c	src/err.c\
				src/win_bonus.c		src/draw.c			src/key_hooks_b.c\
				src/animation.c		src/enemy.c

INCLUDES	= inc/so_long.h inc/libft.h inc/mlx.h

LIBFT		= libft/libft.a
LIBMLX		= minilibx_opengl/libmlx.a

OBJS		= ${SRCS:%.c=%.o}
OBJS_B		= ${SRCS_B:%.c=%.o}

FLAGS		= -Wall -Wextra -Werror
LFLAGS		= -L libft/ -lft -L minilibx_opengl -lmlx -framework OpenGL -framework AppKit

all			: ${NAME}

${NAME}		: ${LIBFT} ${LIBMLX} ${INCLUDES} ${OBJS}
	gcc ${FLAGS} ${LFLAGS} ${OBJS} -o ${NAME}

%.o			: %.c ${INCLUDES}
	gcc ${FLAGS} -Imlx -c $< -o $@

${LIBFT}		:
	make all -C libft/

${LIBMLX}		:
	make all -C minilibx_opengl/
#
bonus			: ${NAME_B}

${NAME_B}		: ${LIBFT} ${LIBMLX} ${INCLUDES} ${OBJS_B}
	gcc ${FLAGS} ${LFLAGS} ${OBJS_B} -o ${NAME_B}

clean		:
	rm -rf ${OBJS}
	make clean -C libft/
	make clean -C minilibx_opengl

fclean		: clean
	rm -rf ${NAME} ${NAME_B}
	rm -rf ${LIBMLX}
	make fclean -C libft/

re			: fclean all
	make re -C minilibx_opengl/

.PHONY	: all clean fclean re bonus
