# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 18:56:56 by decordel          #+#    #+#              #
#    Updated: 2021/11/01 20:21:07 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c\
				sources/ft_x_type.c\
				sources/ft_u_type.c\
				sources/ft_s_type.c\
				sources/ft_c_type.c\
				sources/ft_d_type.c\
				sources/ft_p_type.c

OBJS		= ${SRCS:%.c=%.o}

FLAGS		= -c -Wall -Wextra -Werror

INCLUDES	= includes/*.h

all			: ${NAME}

$(NAME)		: ${OBJS} ${INCLUDES}
	ar -rcs ${NAME} ${OBJS}

%.o		:	%.c
	gcc ${FLAGS} -c $< -o $@

clean		:
	@rm -rf ${OBJS}

fclean		: clean
	@rm -rf ${NAME}

re			: fclean all
