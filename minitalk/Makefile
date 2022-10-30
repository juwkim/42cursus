# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 08:36:51 by juwkim            #+#    #+#              #
#    Updated: 2022/10/30 17:44:07 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS			=	-Wall -Werror -Wextra
LIB				=	./ft_printf

SRC_SERVER_m	=	srcs_server/server.c
SRC_CLIENT_m	=	srcs_client/client.c
SRC_SERVER_b	=	srcs_server/server_bonus.c
SRC_CLIENT_b	=	srcs_client/client_bonus.c

SRC_SERVER		= 	$(if $(filter bonus, $(MAKECMDGOALS)), $(SRC_SERVER_b), $(SRC_SERVER_m))
SRC_CLIENT		= 	$(if $(filter bonus, $(MAKECMDGOALS)), $(SRC_CLIENT_b), $(SRC_CLIENT_m))
OBJS_SERVER		=	$(SRC_SERVER:.c=.o)
OBJS_CLIENT		=	$(SRC_CLIENT:.c=.o)
DEPS_SERVER 	= 	$(SRC_SERVER:.c=.d)
DEPS_CLIENT 	= 	$(SRC_CLIENT:.c=.d)
-include $(DEPS_SERVER)
-include $(DEPS_CLIENT)

NAME			=	server client

all				:	$(NAME)
bonus			: 	$(NAME)

server		:	$(OBJS_SERVER)
				make -C $(LIB)
				$(CC) $(CFLAGS) $(LIB)/libftprintf.a $^ -o $@

client		:	$(OBJS_CLIENT)
				make -C $(LIB)
				$(CC) $(CFLAGS) $(LIB)/libftprintf.a $^ -o $@

clean		:
				$(RM) ./srcs_client/*.o ./srcs_server/*.o

fclean		:	clean
				$(RM) $(NAME)
				make fclean -C $(LIB)

re			:	| fclean all

.PHONY		:	all clean fclean re bonus