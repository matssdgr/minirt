/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:45:07 by mgoguely          #+#    #+#             */
/*   Updated: 2026/11/13 20:21:30 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_dot(t_vec3 a, t_vec3 b)
{
	double	l;

	l = a.x * b.x + a.y * b.y + a.z * b.z;
	return (l);
}

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = (a.y * b.z - a.z * b.y);
	c.y = (a.z * b.x - a.x * b.z);
	c.z = (a.x * b.y - a.y * b.x);
	return (c);
}

t_vec3	ray_at(t_ray ray, double t)
{
	return (vec_add(ray.origin, vec_scale(ray.dir, t)));
}

double	calcul_abc(t_object cyl, t_ray ray, int i)
{
	double	x;
	t_vec3	oc;
	double	t;

	if (i != 1 && i != 2 && i != 0)
		return (-1);
	oc = vec_sub(ray.origin, cyl.pos);
	if (i == 0)
	{
		t = pow(vec_dot(ray.dir, cyl.dir), 2);
		x = vec_dot(ray.dir, ray.dir) - t;
	}
	if (i == 1)
	{
		t = vec_dot(ray.dir, cyl.dir) * vec_dot(oc, cyl.dir);
		x = 2 * (vec_dot(ray.dir, oc) - t);
	}
	if (i == 2)
	{
		t = pow(vec_dot(oc, cyl.dir), 2);
		x = vec_dot(oc, oc) - t;
		x = x - pow(cyl.radius, 2);
	}
	return (x);
}
