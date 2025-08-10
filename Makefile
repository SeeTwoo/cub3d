NAME=cub3d
LIBFTNAME=libft.a
CC=cc
INCLUDE= -Iheader
CFLAGS=-Wall -Werror -Wextra -Ilibft -g3
DFLAGS= $(CFLAGS) -g3
LIBFLAGS= -lft -Llibft
LIBFTDIR = ./libft

SRC=    src/main.c \
		src/parsing/parsing.c \
		src/parsing/verif_pre_open.c \
		src/parsing/open_file.c \
		src/parsing/file_is_valid.c \
		src/parsing/setup_valid.c \
		src/parsing/get_color.c \
		src/parsing/parse_map.c \
		src/parsing/map_is_closed.c \
		src/parsing/reverse_map.c \
		src/parsing/fill_with_one.c \
		src/parsing/get_pos_player.c \
		src/parsing/add_map_line.c \
		src/utils/error_message.c \
		src/utils/close_all_fd.c \
		src/utils/init.c \
		src/utils/close_mlx.c \
		src/utils/skip_white.c \
		src/utils/free_texture.c \
		src/utils/free_linked_list.c \
		src/utils/free_clean.c \
		src/utils/skip_empty_line.c \
		src/exec/cleaners.c \
		src/exec/events.c \
		src/exec/init.c \
		src/exec/keyboard_events.c \
		src/exec/raycasting.c \
		src/exec/render.c \
		src/exec/vectors.c \
		src/exec/wasd_movements.c
	
OBJ_DIR=obj
OBJS=$(SRC:%.c=$(OBJ_DIR)/%.o)

MLX_DIR = ./minilibx-linux
INCLUDES = -I$(MLX_DIR) -Iincludes

LDFLAGS = -L$(MLX_DIR) -lmlx -lm -lX11 -lXext
MLX = $(MLX_DIR)/libmlx.a

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(MLX) $(OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFLAGS) $(MLX) -lXext -lX11 -lm

$(MLX):
	$(MAKE) -C $(MLX_DIR)

debug: fclean
	$(MAKE) CFLAGS="$(DFLAGS)" all

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all

all: $(NAME)

default: all

.PHONY: all re clean fclean
