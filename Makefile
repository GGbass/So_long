# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:20:21 by gongarci          #+#    #+#              #
#    Updated: 2024/09/09 17:26:30 by gongarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
NAME = so_long

INCLUDES = -I/usr/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

NAMEB = bonus

SRC =	./src/check_argv.c \
		./src/tools2.c \
		./src/tools.c \
		./src/check_map.c \
		./src/free.c \
		./src/load_data.c \
		./src/main.c \

SRCB =	./srcb/move_ghost.c \
		./srcb/check_argv_bonus.c \
		./srcb/tools2_bonus.c \
		./srcb/tools_bonus.c \
		./srcb/check_map_bonus.c \
		./srcb/free_bonus.c \
		./srcb/load_data_bonus.c \
		./srcb/main_bonus.c \

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address,leak
CC = gcc
#-no-pie

all: $(NAME) show_progress

$(NAME): $(OBJ)
	@make -s -C libft
	@make -s -C mlx
	@cp ./mlx/libmlx_Linux.a .
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES)  $(MLX_FLAGS) -L libft -lft -o so_long

show_progress:
		@for file in $(SRC); do \
			echo "$(GREEN)Compiling $$file "; \
		done; \
		echo "Compiled: 100%$(DEFAULT)"; \

#-c -o $@ $<

bonus:

$(NAMEB): $(OBJB) show_progress2
	@make -s -C libft
	@make -s -C mlx
	@cp ./mlx/libmlx_Linux.a .
	$(CC) $(CFLAGS) $(OBJB) $(INCLUDES)  $(MLX_FLAGS) -L libft -lft -o so_long_bonus

show_progress2:
		@for file in $(SRCB); do \
			echo "$(GREEN)Compiling $$file "; \
		done; \
		echo "Compiled: 100%$(DEFAULT)"; \

clean:
	rm -f  $(NAME)
	@make fclean -s -C libft
	@rm -f libmlx_Linux.a
	@make clean -C mlx
	rm -f 
	rm -f $(NAMEB)

fclean: clean
	rm -f  $(OBJ)
	rm -f $(OBJB)
	@make fclean -s -C libft
	@rm -f libmlx_Linux.a
	@rm -f libmlx.a

re: fclean all

re_bonus: fclean bonus
	rm -f $(NAMEB)

git:
	git add .
	git commit
	git push

.PHONY: clean fclean re all