# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/23 11:31:01 by hcaspar           #+#    #+#              #
#    Updated: 2017/07/12 15:05:49 by hcaspar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fdf
CC =			gcc

MLX_DIR =		mlx
MLX_INC =		$(MLX_DIR)
MLX_FLAG =		-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIB_DIR =		libft
LIB_INC =		$(LIB_DIR)/includes
LIB_FLAG =		-L $(LIB_DIR) -lft

INC_DIR =		include $(MLX_INC) $(LIB_INC)
SRC_DIR =		src
OBJ_DIR =		obj

SRC_NAME =		get_next_line.c\
				hooks.c\
				main.c\
				mlx_init.c\
				parsing.c\
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
	make -C $(LIB_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(MLX_FLAG) $(LIB_FLAG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX_DIR) clean
	make -C $(LIB_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_DIR)
