NAME = cub3D
SRC =	main.c  parsing/parse.c parsing/ft_split.c rendering.c utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		movements.c mlx_handling.c rotations.c parsing/parse_elem.c free.c parsing/parse_map.c raycasting/raycasting.c raycasting/raycasting_utils.c\
		mlx/mlx.c utils2.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g -I. -Iget_next_line -IMLX42/include
CC = cc 
HDR = header.h get_next_line/get_next_line.h
MLX=./MLX42/build/libmlx42.a
LFLAGS := -framework Cocoa -framework OpenGL -framework IOKit -L ~/.brew/opt/glfw/lib -l glfw3
RED=\033[0;31m
GRN=\033[0;32m
YEL=\033[1;33m
ORANGE= \033[38;5;208m
RESET=\033[0m

all: $(NAME)

$(MLX):
	@if [ ! -f "$(MLX)" ]; then\
		echo "$(YEL)MLX42 not found, setting it up...$(RESET)";\
		rm -rf MLX42;\
		git clone https://github.com/codam-coding-college/MLX42.git;\
		cd MLX42 && cmake -B build && cmake --build build;\
	else\
		echo "$(GRN)MLX42 already exists$(RESET)";\
	fi

$(NAME): $(OBJ) $(MLX)  
	$(CC) $(CFLAGS) $(MLX) $(LFLAGS) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.c $(HDR) | $(MLX)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean