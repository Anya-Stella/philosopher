# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 15:15:03 by tishihar          #+#    #+#              #
#    Updated: 2025/04/17 17:23:52 by tishihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===============================================================================
#                                基本設定
#===============================================================================

# name of project
NAME := philo

# compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3


# for dev and debug
DEVFLAGS := -O0 -g -fsanitize=address

# valgrind
VALGRIND := valgrind
VALGRINDFLAGS :=  --leak-check=full
ARGS ?=
#===============================================================================
#                               ディレクトリ設定
#===============================================================================

# source_code and object_code directory
SRC_DIR := src
OBJ_DIR := bin

# libft

# include
INC_DIR := include
INCLUDES := -I$(INC_DIR)
#===============================================================================
#                              ソースファイル設定
#===============================================================================

SRCS := \
	create_persons.c \
	destroy.c \
	info_setting.c \
	launch_philo.c \
	routine_monitor.c \
	routine_philo.c \
	lonly_philosopher.c \
	print.c \
	time.c \
	utils.c \
	test.c \
    main.c \

# replace object (.c → .o)
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)
#===============================================================================
#                              ライブラリ設定
#===============================================================================

# PATH of libft.a

#===============================================================================
#                    　---ここから下は変えなくていい---
#===============================================================================
#===============================================================================
#                                ルール定義
#===============================================================================

all: $(NAME)

# use: make dev
dev: CFLAGS += $(DEVFLAGS)
dev: LDFLAGS += $(DEVFLAGS)
dev: all

# use: make run ARGS="1 2 3" or make run
run: all $(NAME)
	$(VALGRIND) $(VALGRINDFLAGS) ./$(NAME) $(ARGS)

# main(linker) rule
$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

# compile rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# generate libft.a

# cleans
clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all
devre: fclean dev

# phony
.PHONY: all dev devre clean fclean re
