# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 18:38:46 by juwkim            #+#    #+#              #
#    Updated: 2022/05/05 22:34:58 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES : .c .o

CC		= gcc

INC		= -I includes
CFLAGS	= -Wall -Wextra -Werror $(INC)

SRCS	= srcs/main.c srcs/cat.c
OBJS	= ${SRCS:.c=.o}

NAME	= ft_cat

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
