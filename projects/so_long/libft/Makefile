# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decordel <decordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 10:40:48 by decordel          #+#    #+#              #
#    Updated: 2021/12/14 00:13:16 by decordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_isalnum.c\
			ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_isprint.c\
			ft_itoa.c		ft_memchr.c		ft_memcmp.c		ft_memcpy.c\
			ft_memmove.c	ft_memset.c		ft_putchar_fd.c	ft_putendl_fd.c\
			ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c		ft_strchr.c\
			ft_strdup.c		ft_striteri.c	ft_strjoin.c	ft_strlcat.c\
			ft_strlcpy.c	ft_strlen.c		ft_strmapi.c	ft_strncmp.c\
			ft_strnstr.c	ft_strrchr.c	ft_strtrim.c	ft_substr.c\
			ft_lstnew.c		ft_lstadd_back.c	ft_lstadd_front.c\
			ft_lstclear.c	ft_lstdelone.c		ft_lstiter.c\
			ft_lstlast.c	ft_lstmap.c			ft_lstsize.c

OBJS	=	${SRCS:%.c=%.o}

FLAGS	=	-Wall -Wextra -Werror

all		:	${NAME}

$(NAME)	:	${OBJS}
	@ar rcs ${NAME} $?

%.o		:	%.c
	@gcc ${FLAGS} -c $< -o $@

clean	:
	@rm -f ${OBJS} ${OBJS_B}

fclean	: clean
	@rm -f ${NAME}

re		: fclean all

.PHONY	: all clean fclean re bonus


