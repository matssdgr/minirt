/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:44:01 by mgoguely          #+#    #+#             */
/*   Updated: 2026/11/11 20:11:36 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

double	light(t_scene scene, t_hit hit, t_light *l)
{
	t_vec3	li;
	double	pl;

	if (shadow(scene, hit, l) == 1)
		return (0.0);
	li = vec_sub(l->pos, hit.point);
	li = vec_normalize(li);
	pl = vec_dot(hit.normal, li);
	if (pl < 0.0)
		pl = 0.0;
	pl = pl * l->ratio;
	return (pl);
}

t_vec3	calc_ambient(t_scene scene)
{
	return (vec_scale(scene.ambient_color, scene.ambient_ratio));
}

double	calc_specular(t_hit hit, t_light *l, t_vec3 view)
{
	t_vec3	li;
	t_vec3	r;
	double	rv;

	li = vec_normalize(vec_sub(l->pos, hit.point));
	r = vec_sub(vec_scale(hit.normal, 2.0 * vec_dot(hit.normal, li)), li);
	rv = vec_dot(r, view);
	if (rv <= 0.0)
		return (0.0);
	return (l->ratio * pow(rv, SHININESS));
}

t_vec3	get_final_color(t_hit hit, t_scene scene, t_vec3 view)
{
	t_vec3	total_light;
	t_vec3	final_color;
	double	spec;

	total_light = vec_add(calc_ambient(scene), calc_diffuse(scene, pl));
	final_color = vec_multiply(hit.object->color, total_light);
	final_color = vec_scale(final_color, 1.0 / 255.0);
	if (pl > 0.0)
	{
		spec = calc_specular(scene, hit, view);
		final_color = vec_add(final_color, vec_scale(scene.light.color, spec));
	}
	final_color = norm_color(final_color);
	return (final_color);
}

int	get_mlx_color(t_vec3 color)
{
	int	rgb;

	rgb = (int)color.x << 16 | (int)color.y << 8 | (int)color.z;
	return (rgb);
}

int	get_ray_color(t_ray *ray, t_scene scene)
{
	t_hit	hit;
	double	pl;
	t_vec3	final_color;

	hit = get_closest_hit(scene, ray);
	if (hit.t > 0.0)
	{
		pl = light(scene, hit);
		final_color = get_final_color(hit, scene, pl, vec_scale(ray->dir,
				-1.0));
		return (get_mlx_color(final_color));
	}
	return (0x000000);
}