/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 23:24:53 by mgoguely          #+#    #+#             */
/*   Updated: 2026/11/13 20:18:45 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vec3	vec_scale(t_vec3 v, double scale)
{
	v.x *= scale;
	v.y *= scale;
	v.z *= scale;
	return (v);
}

double	vec_length(t_vec3 v)
{
	double	l;

	l = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
	l = sqrt(l);
	return (l);
}

t_vec3	vec_normalize(t_vec3 v)
{
	double	l;

	l = vec_length(v);
	if (l > 0)
	{
		v.x /= l;
		v.y /= l;
		v.z /= l;
	}
	return (v);
}
