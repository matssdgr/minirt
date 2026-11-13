/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:47:33 by mgoguely          #+#    #+#             */
/*   Updated: 2026/11/13 19:10:38 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx_app.h"

void	init_camera(t_camera *cam)
{
	double	ratio;
	t_vec3	global_up;
	t_vec3	center;

	ratio = 1920.0 / 1080.0;
	cam->width = 2.0 * tan((cam->fov * (PI / 180.0)) / 2);
	cam->height = cam->width / ratio;
	global_up.x = 0.0;
	global_up.y = 1.0;
	global_up.z = 0.0;
	if (cam->dir.y == 1.0 || cam->dir.y == -1.0)
	{
		global_up.y = 0.0;
		global_up.z = 1.0;
	}
	cam->right = vec_normalize(vec_cross(global_up, cam->dir));
	cam->up = vec_cross(cam->dir, cam->right);
	center = vec_add(cam->pos, cam->dir);
	cam->up_left = vec_sub(center, vec_scale(cam->right, cam->width / 2));
	cam->up_left = vec_add(cam->up_left, vec_scale(cam->up, cam->height / 2));
	cam->pixel_delta_x = vec_scale(cam->right, cam->width / WIDTH);
	cam->pixel_delta_y = vec_scale(cam->up, -cam->height / HEIGHT);
}

void	render_scene(t_app *app, t_camera *cam)
{
	int		i;
	int		j;
	t_vec3	pixel;
	t_ray	ray;

	j = 0;
	ray.origin = cam->pos;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			pixel = vec_add(cam->up_left, vec_scale(cam->pixel_delta_x, i));
			pixel = vec_add(pixel, vec_scale(cam->pixel_delta_y, j));
			ray.dir = vec_normalize(vec_sub(pixel, cam->pos));
			put_pixel(&app->img, i, j, get_ray_color(&ray, app->scene));
			i++;
		}
		j++;
	}
}
