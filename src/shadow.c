/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 20:44:01 by mgoguely          #+#    #+#             */
/*   Updated: 2026/11/10 17:33:25 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	shadow(t_scene scene, t_hit hit, t_ray *shadow)
{
	t_vec3		offset;
	double		length;
	t_hit		block;

	offset = vec_scale(hit.normal, 0.001);
	shadow->origin = vec_add(hit.point, offset);
	shadow->dir = vec_sub(scene.light.pos, shadow->origin);
	length = vec_length(shadow->dir);
	shadow->dir = vec_normalize(shadow->dir);
	block = get_closest_hit(scene, shadow);
	if (block.t > 0.001 && block.t < length)
		return (1);
	return (0);
}
