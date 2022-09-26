# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 03:58:18 by juwkim            #+#    #+#              #
#    Updated: 2022/05/04 23:00:59 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -I./includes -Wall -Werror -Wextra
NAME = libft.a
SRCS =	srcs/ft_putchar.c	\
		srcs/ft_swap.c		\
		srcs/ft_putstr.c	\
		srcs/ft_strlen.c	\
		srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}

all : $(NAME)

${NAME}: ${OBJS}
	ar rsc $@ $^

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
