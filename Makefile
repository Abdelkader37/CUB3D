NAME = cub3D
SRC = main.c  parsing/parse.c ft_split.c raycasting.c rendering.c utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c movements.c mlx_handling.c rotations.c parsing/parse_elem.c free.c
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
$(NAME): $(OBJ) $(HDR)  
	@if find . -name "libmlx42.a" | grep -q .;then\
		echo "$(GRN)mlx exist$(RESET)";\
	else\
		echo "$(YEL)MLX42 not found, setuping it...$(RESET)";\
		rm -rf MLX42;\
		git clone https://github.com/codam-coding-college/MLX42.git ;\
		cd MLX42 && cmake -B build && cmake --build build;\
		cd -;\
		fi

	$(CC) $(CFLAGS) $(MLX) $(LFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean