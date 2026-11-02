/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:42:26 by amine             #+#    #+#             */
/*   Updated: 2026/11/02 11:56:04 by amine            ###   ########.fr       */
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

void    setup_hooks(t_app *app)
{
    mlx_hook(app->win, EVENT_KEYPRESS, MASK_KEYPRESS, handle_key, app);
    mlx_hook(app->win, EVENT_DESTROY, MASK_NONE, handle_close, app);
    mlx_expose_hook(app->win, handle_expose, app);
}
