NAME		= miniRT

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=42

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11

INCLUDES	= -I. -Isrc/parse -Imlx -Iget_next_line -I$(LIBFT_DIR) -I$(MLX_DIR)

OBJ_DIR		= obj

SRCS		= src/main.c \
			  src/rgb_utils.c \
			  src/sphere.c \
			  src/vector_utils.c \
			  src/vector_utils2.c \
			  mlx/mlx_hooks.c \
			  mlx/mlx_init.c \
			  mlx/mlx_render.c \
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c \
			  src/parse/parse_elements.c \
			  src/parse/parse_line.c \
			  src/parse/parse_numbers.c \
			  src/parse/parse_objects.c \
			  src/parse/parse_scene.c \
			  src/parse/parse_split.c \
			  src/parse/parse_vectors.c \
			  src/parse/utils.c
#			  src/camera.c \
#			  src/color.c \
#			  src/cylinder.c \
#			  src/plane.c \
#			  src/shadow.c \

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
HEADERS		= minirt.h src/parse/parsing.h mlx/mlx_app.h \
			  get_next_line/get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -lm -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re