/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 22:25:31 by mgoguely          #+#    #+#             */
/*   Updated: 2026/11/13 20:24:04 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_caps(t_object cyl, t_ray ray, t_object plane)
{
	double	t;
	t_vec3	p;

	t = hit_plane(plane, ray);
	if (t <= 0)
		return (0.0);
	p = vec_add(ray.origin, vec_scale(ray.dir, t));
	if (vec_length(vec_sub(p, plane.pos)) <= cyl.radius)
		return (t);
	return (0.0);
}

double	check_caps(t_object cyl, t_ray ray, t_hit *hit)
{
	t_object	plane_top;
	t_object	plane_bottom;
	double		t_top;
	double		t_bottom;

	plane_top.pos = vec_add(cyl.pos, vec_scale(cyl.dir, cyl.height / 2));
	plane_top.dir = cyl.dir;
	plane_bottom.pos = vec_sub(cyl.pos, vec_scale(cyl.dir, cyl.height / 2));
	plane_bottom.dir = vec_scale(cyl.dir, -1);
	t_top = hit_caps(cyl, ray, plane_top);
	t_bottom = hit_caps(cyl, ray, plane_bottom);
	if ((t_bottom <= 0 && t_top > 0) || ((t_top > 0) && t_top < t_bottom))
	{
		hit->normal = cyl.dir;
		return (t_top);
	}
	hit->normal = vec_scale(cyl.dir, -1);
	return (t_bottom);
}

int	check_height(t_object cyl, t_ray ray, t_hit *hit, double t)
{
	double	m;
	t_vec3	q;

	hit->point = ray_at(ray, t);
	m = vec_dot(vec_sub(hit->point, cyl.pos), cyl.dir);
	if (m >= cyl.height / 2.0 || m <= -cyl.height / 2.0)
		return (0);
	q = vec_add(cyl.pos, vec_scale(cyl.dir, m));
	hit->normal = vec_sub(hit->point, q);
	hit->normal = vec_normalize(hit->normal);
	return (1);
}

double	check_tube(t_object cyl, t_ray ray)
{
	double	abc[3];
	double	delta;
	double	t;

	abc[0] = calcul_abc(cyl, ray, 0);
	abc[1] = calcul_abc(cyl, ray, 1);
	abc[2] = calcul_abc(cyl, ray, 2);
	delta = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (delta < 0.0)
		return (-1);
	t = (-abc[1] - sqrt(delta)) / (2 * abc[0]);
	if (t > 0.001)
		return (t);
	t = (-abc[1] + sqrt(delta)) / (2 * abc[0]);
	if (t > 0.001)
		return (t);
	return (-1);
}

int	hit_cylinder(t_object *cyl, t_ray ray, t_hit *hit)
{
	double	t_tube;
	double	t_caps;
	t_hit	tube;
	t_hit	caps;

	t_caps = check_caps(*cyl, ray, &caps);
	t_tube = check_tube(*cyl, ray);
	if (!check_height(*cyl, ray, &tube, t_tube) && t_tube > 0.0)
		t_tube = -1.0;
	if (t_tube > 0.0 && (t_caps <= 0.0 || t_tube < t_caps))
		*hit = tube;
	else if (t_caps > 0.0)
	{
		*hit = caps;
		hit->point = ray_at(ray, t_caps);
		t_tube = t_caps;
	}
	else
		return (0);
	hit->t = t_tube;
	hit->object = cyl;
	return (1);
}
