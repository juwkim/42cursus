# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 08:00:08 by juwkim            #+#    #+#              #
#    Updated: 2022/09/27 20:17:33 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# make                          : debug
# make debug                    : debug 
# make release                  : release
# make clean [debug, release]   : 해당 빌드 경로 파일 삭제
# make rebuild [debug, release] : rebuild 실행

# 1
# The default builds is debug
# Here, Define the common parts of debug and release.
# LDFLAGS is a Link option and is added if necessary.
# CONFIG distinguishes debug/release and affects the build path.
# Build_DIR specifies the path to be used in the build.
# NAME includes the build relative path and the name of executable.

CC = cc
CFLAGS	= -Wall -Wextra -Werror
LDFLAGS = -Iincludes
CONFIG  = debug
BUILD_DIR = ./
NAME = $(BUILD_DIR)/libftprintf.a

# 2
#########################
# Identify the argument #
#########################

ifneq ($(findstring debug, $(MAKECMDGOALS)), )
    ARG.DEBUG = 1
endif

ifneq ($(findstring release, $(MAKECMDGOALS)), )
    ARG.RELEASE = 1
endif

ifneq ($(findstring clean, $(MAKECMDGOALS)), )
    ARG.CLEAN = 1
endif

ifneq ($(findstring rebuild, $(MAKECMDGOALS)), )
    ARG.REBUILD = 1
endif

# 3
###############################
# Distinguishes debug/release #
###############################

ifeq ($(ARG.DEBUG), 1)
    CFLAGS    += -g -DDEBUG
    CONFIG     = debug
else
    CFLAGS    += -O -DNDEBUG
    CONFIG     = release
endif

# 4
########
# make #
########

.PHONY: debug release build clean rebuild PRE_BUILD POST_BUILD all


SRC_DIR = ./srcs
OBJ_DIR = ./objs

$(shell [ ! -d $(OBJ_DIR) ] && mkdir -p $(OBJ_DIR))

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcus $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -MD $(LDFLAGS)

clean :
	rm -f $(OBJS) $(DEPS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re directories

-include $(DEPS)