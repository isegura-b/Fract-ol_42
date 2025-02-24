# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 22:48:51 by isegura-          #+#    #+#              #
#    Updated: 2025/02/23 23:20:23 by isegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = ./src
OBJ_DIR = ./obj
MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lX11 -lXext -lm -lXrandr -lXinerama -lXcursor -lXrender -lXfixes -lpthread

SRC = $(SRC_DIR)/events.c \
      $(SRC_DIR)/fractol_utils.c \
      $(SRC_DIR)/init.c \
      $(SRC_DIR)/main.c \
      $(SRC_DIR)/math_utils.c \
      $(SRC_DIR)/render.c \
	  $(SRC_DIR)/parsing.c \

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

INCLUDE = $(MLX_DIR)/mlx.h \
          $(MLX_DIR)/mlx_int.h \
          $(SRC_DIR)/fractol.h

all: libs $(NAME)

libs:
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
