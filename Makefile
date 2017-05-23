# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/23 11:31:01 by hcaspar           #+#    #+#              #
#    Updated: 2017/05/23 17:28:16 by hcaspar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fdf
CC =			gcc

MLX_DIR =		mlx
MLX_INC =		$(MLX_DIR)
MLX_FLAG =		-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

INC_DIR =		include $(MLX_INC)
SRC_DIR =		src
OBJ_DIR =		obj

SRC_NAME =		hooks.c\
				main.c\
				mlx_init.c\
				prog_exit.c\
				render.c

OBJ_NAME =		$(SRC_NAME:.c=.o)

SRC =			$(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJ =			$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))
INC =			$(addprefix -I ,$(INC_DIR))

CFLAGS =		-Wall -Werror -Wextra $(INC)

.PHONY: all clean fclean re norme

all: libs $(NAME)

libs:
	make -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(MLX_FLAG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_DIR)
