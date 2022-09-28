# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 04:59:36 by juwkim            #+#    #+#              #
#    Updated: 2022/09/26 12:46:37 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pipe

SRCS		= $(filter-out ft_l%.c, $(wildcard *.c))
BNS_SRCS	= $(wildcard ft_l*.c)

OBJS		= 	$(SRCS:.c=.o)
BNS_OBJS	=	$(BNS_SRCS:.c=.o)

NAME 		= libft.a

all 	: 	$(NAME)
bonus	:	$(NAME)

$(NAME)	: 	$(OBJS) $(if $(filter bonus, $(MAKECMDGOALS)), $(BNS_OBJS))
			ar rcs $@ $^

clean	:
			rm -f $(OBJS) $(BNS_OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus