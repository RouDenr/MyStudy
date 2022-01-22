# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:26:21 by decordel          #+#    #+#              #
#    Updated: 2022/01/23 00:24:01 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= a.out

SRCS		=	main.c\
					src/${NAME}.c

OBJS		= ${SRCS:%.c=%.o}

INCS		= inc/${NAME}.h

LIBFT		= libft/libft.a

CC		= gcc

FLAGS	= -g -Wall -Wextra -Werror
LFLAGS	= -L libft/ -lft

all		: ${NAME}

${NAME}	: ${INCS} ${OBJS} ${LIB}
	${CC} ${FLAGS} ${LFLAGS} ${OBJS} -o ${NAME}

%.o		: %.c ${INCS}
	${CC} ${FLAGS} -c $< -o $@

${LIB}	:
	@make all -C libft/

clean	:
	@rm -rf ${OBJS}
	@make clean -C libft/

fclean	: clean
	rm -rf ${NAME}
	@make fclean -C libft/

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

URL = ""

#git clone ${URL} ${NAME}

start_project	:
	mkdir ${NAME}
	cp -r libft ${NAME}/
	cp Makefile ${NAME}/
	cp .gitignore ${NAME}
	mkdir ${NAME}/inc
	mkdir ${NAME}/src
	touch ${NAME}/main.c
	touch ${NAME}/inc/${NAME}.h
	touch ${NAME}/src/${NAME}.c

.PHONY	: all clean fclean re git do sh leaks debug norm
