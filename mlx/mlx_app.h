/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_app.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:25:24 by mgoguely          #+#    #+#             */
/*   Updated: 2026/11/13 20:25:28 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_APP_H
# define MLX_APP_H

# include "minirt.h"
# include "parsing.h"
# include <mlx.h>
# include <stdlib.h>

# define WIDTH 1280
# define HEIGHT 720

# define KEY_ESC 65307
# define EVENT_KEYPRESS 2
# define EVENT_DESTROY 17
# define MASK_KEYPRESS 1L
# define MASK_NONE 0L

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_app
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_scene	scene;
}			t_app;

/* mlx_init */
int			init_app(t_app *app);
void		destroy_app(t_app *app);
/* mlx_hooks */
void		setup_hooks(t_app *app);
/* mlx_render */
void		put_pixel(t_img *img, int x, int y, int color);
void		render_placeholder(t_app *app);
void		render_scene(t_app *app, t_camera *cam);

#endif
