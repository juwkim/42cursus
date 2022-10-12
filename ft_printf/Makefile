# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 05:18:16 by juwkim            #+#    #+#              #
#    Updated: 2022/10/12 18:58:13 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rsc

src_m = ft_printf.c 	\
		ft_utils.c 		\
		ft_set_option.c \
		ft_out.c

src_b = ft_printf_bonus.c 		\
		ft_utils_bonus.c 		\
		ft_set_option_bonus.c	\
		ft_out_bonus.c

NAME = libftprintf.a

SRCS = $(if $(filter bonus, $(MAKECMDGOALS)), $(src_b), $(src_m))
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

all: $(NAME)
bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: | fclean all

.PHONY: all clean fclean re bonus