NAME = BSQ
SOURCE = srcs/main.c srcs/solve.c srcs/parse.c srcs/t_array.c srcs/t_map.c
HEADER = includes
OBJS = $(SOURCE:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME) : $(OBJS)
		$(CC) $(CFALGS) $(OBJS) -o $(NAME)

clean :
			$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)

re : fclean all
