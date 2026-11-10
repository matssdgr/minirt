/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:53:30 by mgoguely          #+#    #+#             */
/*   Updated: 2026/11/10 17:36:45 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_impact(t_object *obj, t_ray *ray, t_hit *temp)
{
	if (obj->type == SPHERE)
		return (impact_point(obj, *ray, temp));
	if (obj->type == PLANE)
		return (impact_plane(obj, *ray, temp));
	if (obj->type == CYLINDER)
		return (hit_cylinder(obj, *ray, temp));
	return (0);
}

t_hit	get_closest_hit(t_scene scene, t_ray *ray)
{
	t_hit		closest;
	t_hit		temp;
	t_object	*obj;

	closest.t = -1.0;
	obj = scene.objects;
	while (obj)
	{
		if (check_impact(obj, ray, &temp))
		{	
			if (closest.t < 0.0 || temp.t < closest.t)
				closest = temp;
		}
		obj = obj->next;
	}
	return (closest);
}