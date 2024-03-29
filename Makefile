# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:26:21 by decordel          #+#    #+#              #
#    Updated: 2022/11/05 04:28:24 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= a.out

S			=	logic_src/
O			=	obj
D			=	deps
I			=	incs/

SRCS		=	main.c\
					src/${NAME}.c

OBJS		= ${SRCS:$S%.c=$O/%.o}

INCS		= inc/${NAME}.h

LIBFT		= libft/libft.a

CC		= gcc

FLAGS	= -g -Wall -Wextra -Werror
LFLAGS	= -L libft/ -lft

all		: ${NAME}

${NAME}	: ${INCS} ${OBJS} ${LIB}
	${CC} ${FLAGS} ${LFLAGS} ${OBJS} -o ${NAME}

# Building objective files (*.o)
$O			:
	@mkdir $@

$O/%.o		: $S%.c ${INCS} | $O
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

git_sub ?=  $(shell bash -c 'read -p "$$(echo git : ) " git_sub; echo $$git_sub')
name_sub ?=  $(shell bash -c 'read -p "$$(echo name : ) " name_sub; echo $$name_sub')

add_submodule	:
	git submodule add ${git_sub} projects/${name_sub}


path-to-submodule =  $(shell bash -c 'read -p "$$(echo submodule : ) " submodule; echo $$submodule')
rm_submodule	:

# git rm projects/${path-to-submodule}
# rm -rf .git/modules/projects/${path-to-submodule}
# git config --remove-section submodule.projects/${path-to-submodule}/.
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

FOLDER_NAME = projects/${NAME}

start_project	:
#git clone ${URL} ${FOLDER_NAME}
	mkdir ${FOLDER_NAME}
	cp -r projects/libft ${FOLDER_NAME}/
	cp Makefile ${FOLDER_NAME}/
	cp .gitignore ${FOLDER_NAME}
	mkdir ${FOLDER_NAME}/inc
	mkdir ${FOLDER_NAME}/src
	touch ${FOLDER_NAME}/main.c
	touch ${FOLDER_NAME}/inc/${NAME}.h
	touch ${FOLDER_NAME}/src/${NAME}.c

.PHONY	: all clean fclean re git do sh leaks debug norm
