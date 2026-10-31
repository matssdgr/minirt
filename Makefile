NAME		= miniRT

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=42
INCLUDES	= -I. -Isrc/parse -Ilibft

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= main.c \
			  rgb_utils.c \
			  sphere.c \
			  vector_utils.c \
			  vector_utils2.c \
			  parse/get_next_line.c \
			  parse/get_next_line_utils.c \
			  parse/parse_elements.c \
			  parse/parse_line.c \
			  parse/parse_numbers.c \
			  parse/parse_objects.c \
			  parse/parse_scene.c \
			  parse/parse_split.c \
			  parse/parse_vectors.c \
			  parse/scene_free.c
#			  camera.c \
#			  color.c \
#			  cylinder.c \
#			  plane.c \
#			  shadow.c \

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
HEADERS		= minirt.h src/parse/parsing.h

# MiniLibX (a activer plus tard)
# MLX_DIR	= minilibx-linux
# MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11
# INCLUDES	+= -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -lm -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
