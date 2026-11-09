/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:42:26 by amine             #+#    #+#             */
/*   Updated: 2026/11/09 14:37:21 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_app.h"

static int  handle_key(int keycode, t_app *app)
{
    if (keycode == KEY_ESC)
    {
        destroy_app(app);
        exit(0);
    }
    return (0);
}

static int  handle_close(t_app *app)
{
    destroy_app(app);
    exit(0);
    return (0);
}

static int  handle_expose(t_app *app)
{
    mlx_put_image_to_window(app->mlx, app->win, app->img.ptr, 0, 0);
    return (0);
}

void	setup_hooks(t_app *app)
{
	int (*f_key)(void);
	int (*f_close)(void);
	int (*f_expose)(void);

	f_key = (int (*)(void))(void *)handle_key;
	f_close = (int (*)(void))(void *)handle_close;
	f_expose = (int (*)(void))(void *)handle_expose;

	mlx_hook(app->win, EVENT_KEYPRESS, MASK_KEYPRESS, f_key, app);
	mlx_hook(app->win, EVENT_DESTROY, MASK_NONE, f_close, app);
	mlx_expose_hook(app->win, f_expose, app);
}
