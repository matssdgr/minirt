/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 14:27:23 by mgoguely          #+#    #+#             */
/*   Updated: 2026/09/20 15:43:58 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_sphere(t_object sphere, t_ray ray)
{
	t_vec3	l;
	double	abc[3];
	double	delta;
	double	t;

	l = vec_sub(ray.origin, sphere.pos);
	abc[0] = vec_dot(ray.dir, ray.dir);
	abc[1] = 2.0 * vec_dot(ray.dir, l);
	abc[2] = vec_dot(l, l) - (sphere.radius * sphere.radius);
	delta = (abc[1] * abc[1]) - (4.0 * abc[0] * abc[2]);
	t = (-abc[1] - sqrt(delta)) / (2.0 * abc[0]);
	if (t > 0.001)
		return (t);
	t = (-abc[1] + sqrt(delta)) / (2.0 * abc[0]);
	if (t > 0.001)
		return (t);
	return (-1);
}

t_vec3	sphere_normale(t_object sphere, t_vec3 hit_point)
{
	t_vec3	n;

	n = vec_sub(hit_point, sphere.pos);
	n = vec_normalize(n);
	return (n);
}

int	impact_point(t_object *sphere, t_ray ray, t_hit *hit)
{
	double	t;

	t = hit_sphere(*sphere, ray);
	if (t < 0.001)
		return (0);
	hit->t = t;
	hit->point = ray_at(ray, t);
	hit->normal = sphere_normale(*sphere, hit->point);
	hit->object = sphere;
	return (1);
}


