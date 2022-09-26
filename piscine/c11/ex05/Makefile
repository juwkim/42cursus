# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 18:38:46 by juwkim            #+#    #+#              #
#    Updated: 2022/05/05 20:48:58 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES : .c .o

CC		= gcc

INC		= -I includes
CFLAGS	= -Wall -Wextra -Werror $(INC)

SRCS	= srcs/ft_atoi.c \
		  srcs/print.c \
		  srcs/main.c \
		  srcs/operation.c
OBJS	= ${SRCS:.c=.o}

TARGET	= do-op

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${TARGET}

re : fclean all

.PHONY: all clean fclean re
