/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 20:44:01 by mgoguely          #+#    #+#             */
/*   Updated: 2026/09/24 14:52:48 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	shadow(t_scene scene, t_hit hit, t_ray *shadow)
{
	t_vec3		offset;
	double		length;
	double		t;
	t_object	*obj;

	offset = vec_scale(hit.normal, 0.001);
	shadow->origin = vec_add(hit.point, offset);
	shadow->dir = vec_sub(scene.light.pos, hit.point);
	length = vec_length(shadow->dir);
	shadow->dir = vec_normalize(shadow->dir);
	obj = scene.objects;
	while (obj)
	{
		if (obj->type == SPHERE)
			t = hit_sphere(*obj, *shadow);
		else if (obj->type == CYLINDER)
			t = hit_cylinder(*obj, *shadow, &hit);
		else if (obj->type == PLANE)
			t = hit_plane(*obj, *shadow);
		if (t > 0.001 && t < length)
			return (1);
		obj = obj->next;
	}
	return (0);
}
