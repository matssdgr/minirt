/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:44:01 by mgoguely          #+#    #+#             */
/*   Updated: 2026/09/25 16:43:44 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	light(t_scene scene, t_hit hit)
{
	t_vec3	li;
	double	pl;
	t_ray	s_ray;

	if (shadow(scene, hit, &s_ray) == 1)
		return (0.0);
	li = vec_sub(scene.light.pos, hit.point);
	li = vec_normalize(li);
	pl = vec_dot(hit.normal, li);
	if (pl < 0.0)
		pl = 0.0;
	pl = pl * scene.light.ratio;
	return (pl);
}

t_vec3	calc_ambient(t_scene scene)
{
	return (vec_scale(scene.ambient_color, scene.ambient_ratio));
}

t_vec3	calc_diffuse(t_scene scene, double pl)
{
	return (vec_scale(scene.light.color, pl));
}

t_vec3	get_final_color(t_hit hit, t_scene scene, double pl)
{
	t_vec3	total_light;
	t_vec3	final_color;

	total_light = vec_add(calc_ambient(scene), calc_diffuse(scene, pl));
	final_color = vec_multiply(hit.object->color, total_light);
	final_color = vec_scale(final_color, 1.0 / 255.0);
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
	if (hit.distance > 0.0)
	{
		pl = light(scene, hit);
		final_color = get_final_color(hit, scene, pl);
		return (get_mlx_color(final_color));
	}
	return (0x000000);
}