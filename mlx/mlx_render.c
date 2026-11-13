/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:56:33 by amine             #+#    #+#             */
/*   Updated: 2026/11/13 20:25:00 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_app.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(unsigned int *)dst = color;
}

void	render_placeholder(t_app *app)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(&app->img, x, y, (x * 255 / WIDTH) << 16 | (y * 255
					/ HEIGHT) << 8 | 128);
			x++;
		}
		y++;
	}
}
