ARFLAGS = rsc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
