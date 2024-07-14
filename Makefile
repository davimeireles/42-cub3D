#	====================		Directories		====================

INCLUDES = headers
SRC = srcs
_SUBFOLDERS = checker initializer keys main map player raycaster \
				screen utils free
VPATH = $(SRCS) $(addprefix $(SRC)/, $(_SUBFOLDERS))
OBJ_DIR = objs

#	====================		Files      		====================

NAME = cub3d

_FILES = file_checker.c flood.c map_checker.c padding.c cub_init.c \
		game_init.c texture_init.c window_init.c cub3d.c \
		main.c screen.c error.c utils.c utils_2.c utils_3.c \
		free_mlx.c player_init.c minimap_init.c minimap.c raycaster.c \
		raycaster_init.c \
		keys.c mouse.c movements.c rotations.c free_cub3d.c

OBJS = $(_FILES:%.c=%.o)
TARGET = $(addprefix $(OBJ_DIR)/, $(OBJS))

#	====================		Flags      		====================

CC = cc
RM = rm

W = -Wall -Wextra -Werror
I = -I $(INCLUDES)
O = -c

WBLOCK = --no-print-directory

LIBFT = -L ./libft -lft
MLX = -L ./minilibx-linux -lmlx -lXext -lX11
MATH =-lm

#	====================		Colors     		====================

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
CYAN = \033[0;36m

B_RED = \033[1;31m
B_GREEN = \033[1;32m
B_BLUE = \033[1;34m
L_BLUE = \033[1;94m
B_YELLOW = \033[1;33m
B_MAGENTA = \033[1;35m
B_CYAN = \033[1;36m

RESET = \033[0m

#	====================		Rules      		====================

all: $(NAME)

$(NAME): $(OBJ_DIR) $(TARGET)
	@make $(WBLOCK) -C ./libft
	@make $(WBLOCK) -C ./minilibx-linux
	@$(CC) $(W) $(TARGET) $(LIBFT) $(MLX) -o $(NAME) $(MATH) 
	@echo "$(B_GREEN)$(NAME) created$(RESET)"
	@clear
	@echo "\e[38;2;255;0;0m==================================================================="
	@echo " ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ "
	@echo "██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗"
	@echo "██║     ██║   ██║██████╔╝ █████╔╝██║  ██║"
	@echo "██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║"
	@echo "╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝"
	@echo " ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝"
	@echo "==================================================================="
	@echo "\e[0mThales Xisto (txisto-d) - Davi Meireles (dmeirele)"
	@echo "$(COLOR_RESET)"
	@echo "\e[?25h"

$(OBJ_DIR)/%.o: %.c
	$(eval COMPTEUR=$(shell echo $$(($(COMPTEUR)+1))))
	@printf "\e[?25l"
	@if test $(COMPTEUR) -eq 1;then \
		printf "$(B_YELLOW)$(NAME)$(RESET):$(YELLOW) Compiling binary files...$(RESET)\n\n";fi
	@printf "\033[A\33[2K\r$(CYAN)Binary $(COMPTEUR): $@$(RESET)\n"
	@$(CC) $(W) $(I) $(O) $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@make $(WBLOCK) clean -C ./libft
	@make $(WBLOCK) clean -C ./minilibx-linux
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(B_YELLOW)$(NAME)$(RESET):$(YELLOW) binary files deleted$(RESET)"

fclean:
	@make $(WBLOCK) fclean -C ./libft
	@make $(WBLOCK) clean -C ./minilibx-linux
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(B_YELLOW)$(NAME)$(RESET):$(YELLOW) binary files deleted$(RESET)"
	@$(RM) -rf $(NAME)
	@echo "$(B_YELLOW)$(NAME)$(RESET):$(YELLOW) deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re

norm:
	norminette -R CheckForbiddenSourceHeader headers/cub3d.h srcs/*.c

leak: all
	valgrind --leak-check=full --show-leak-kinds=all \
		--suppressions=minilibx_leaks ./$(NAME) maps/valid/library.cub

test: all
	./$(NAME) maps/valid/map.cub