/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 19:00:04 by mgoguely          #+#    #+#             */
/*   Updated: 2026/11/13 20:32:35 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vec3	vec_multiply(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	return (result);
}

t_vec3	norm_color(t_vec3 color)
{
	if (color.x > 255.0)
		color.x = 255.0;
	if (color.y > 255.0)
		color.y = 255.0;
	if (color.z > 255.0)
		color.z = 255.0;
	return (color);
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
