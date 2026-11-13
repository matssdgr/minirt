# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/09 12:39:15 by amine             #+#    #+#              #
#    Updated: 2026/11/13 20:29:06 by mgoguely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=42

MLX_DIR		= minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11

INCLUDES	= -I. -Isrc/parse -Imlx -Ilibft_utils -I$(MLX_DIR)

OBJ_DIR		= obj

SRCS		= src/main.c \
			  src/camera.c \
			  src/color.c \
			  src/rgb_utils.c \
			  src/sphere.c \
			  src/cylinder.c \
			  src/plane.c \
			  src/shadow.c \
			  src/intersection.c \
			  src/vector_utils.c \
			  src/vector_utils2.c \
			  mlx/mlx_hooks.c \
			  mlx/mlx_init.c \
			  mlx/mlx_render.c \
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c \
			  libft_utils/ft_bzero.c \
			  libft_utils/ft_isdigit.c \
			  libft_utils/ft_memset.c \
			  libft_utils/ft_putstr_fd.c \
			  libft_utils/ft_split.c \
			  libft_utils/ft_strlcpy.c \
			  libft_utils/ft_strncmp.c \
			  src/parse/parse_elements.c \
			  src/parse/parse_line.c \
			  src/parse/parse_numbers.c \
			  src/parse/parse_objects.c \
			  src/parse/parse_scene.c \
			  src/parse/parse_split.c \
			  src/parse/parse_vectors.c \
			  src/parse/utils.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
HEADERS		= minirt.h src/parse/parsing.h libft_utils/libft_utils.h \
			  mlx/mlx_app.h get_next_line/get_next_line.h

NAME_BONUS	= miniRT_bonus
OBJ_DIR_B	= obj_bonus
INCLUDES_B	= -Ibonus -Ibonus/src/parse -Ibonus/mlx -Ilibft_utils -I$(MLX_DIR)

SRCS_BONUS	= bonus/src/main_bonus.c \
			  bonus/src/camera_bonus.c \
			  bonus/src/color_bonus.c \
			  bonus/src/rgb_utils_bonus.c \
			  bonus/src/sphere_bonus.c \
			  bonus/src/cylinder_bonus.c \
			  bonus/src/plane_bonus.c \
			  bonus/src/shadow_bonus.c \
			  bonus/src/intersection_bonus.c \
			  bonus/src/vector_utils_bonus.c \
			  bonus/src/vector_utils2_bonus.c \
			  bonus/mlx/mlx_hooks_bonus.c \
			  bonus/mlx/mlx_init_bonus.c \
			  bonus/mlx/mlx_render_bonus.c \
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c \
			  libft_utils/ft_bzero.c \
			  libft_utils/ft_isdigit.c \
			  libft_utils/ft_memset.c \
			  libft_utils/ft_putstr_fd.c \
			  libft_utils/ft_split.c \
			  libft_utils/ft_strlcpy.c \
			  libft_utils/ft_strncmp.c \
			  bonus/src/parse/parse_elements_bonus.c \
			  bonus/src/parse/parse_line_bonus.c \
			  bonus/src/parse/parse_numbers_bonus.c \
			  bonus/src/parse/parse_objects_bonus.c \
			  bonus/src/parse/parse_scene_bonus.c \
			  bonus/src/parse/parse_split_bonus.c \
			  bonus/src/parse/parse_vectors_bonus.c \
			  bonus/src/parse/utils_bonus.c

OBJS_BONUS	= $(SRCS_BONUS:%.c=$(OBJ_DIR_B)/%.o)
HEADERS_B	= bonus/minirt_bonus.h bonus/src/parse/parsing_bonus.h \
			  bonus/mlx/mlx_app_bonus.h libft_utils/libft_utils.h \
			  get_next_line/get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR) CC="gcc -std=gnu17"
	$(CC) $(OBJS) $(MLX_FLAGS) -lm -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C $(MLX_DIR) CC="gcc -std=gnu17"
	$(CC) $(OBJS_BONUS) $(MLX_FLAGS) -lm -o $(NAME_BONUS)

$(OBJ_DIR_B)/%.o: %.c $(HEADERS_B)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES_B) -c $< -o $@

clean:
	-$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR) $(OBJ_DIR_B)
	rm -f miniRT_bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re