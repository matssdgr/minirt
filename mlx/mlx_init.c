/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:20:40 by amine             #+#    #+#             */
/*   Updated: 2026/11/13 20:24:57 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_app.h"

int	init_app(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		return (0);
	app->win = mlx_new_window(app->mlx, WIDTH, HEIGHT, "miniRT");
	if (!app->win)
		return (0);
	app->img.ptr = mlx_new_image(app->mlx, WIDTH, HEIGHT);
	if (!app->img.ptr)
		return (0);
	app->img.addr = mlx_get_data_addr(app->img.ptr, &app->img.bpp,
			&app->img.line_len, &app->img.endian);
	if (!app->img.addr)
		return (0);
	return (1);
}

void	destroy_app(t_app *app)
{
	if (app->img.ptr)
		mlx_destroy_image(app->mlx, app->img.ptr);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	free_scene(&app->scene);
}
