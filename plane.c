/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:47:46 by mgoguely          #+#    #+#             */
/*   Updated: 2026/09/22 22:25:21 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_plane(t_object plane, t_ray ray)
{
	double	t;
	double	denom;
	t_vec3	oc;

	denom = vec_dot(ray.dir, plane.dir);
	if (denom > 0.001 || denom < -0.001)
	{
		oc = vec_sub(plane.pos, ray.origin);
		t = vec_dot(oc, plane.dir) / denom;
		return (t);
	}
	return (0.0);
}

void	record_hit_plane(t_object *plane, t_ray ray, double t, t_hit *hit)
{
	hit->point = vec_add(ray.origine, vec_scale(ray.dir, t));
	hit->color = plane->color;
	hit->normal = plane->dir;
	if (vec_dot(ray.dir, hit->normal) > 0.0)
		hit->normal = vec_scale(hit->normal, -1.0);
}

