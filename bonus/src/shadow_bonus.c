/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 20:44:01 by mgoguely          #+#    #+#             */
/*   Updated: 2026/11/13 20:31:19 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	shadow(t_scene scene, t_hit hit, t_light *l)
{
	t_vec3	offset;
	double	length;
	t_hit	block;
	t_ray	sha;

	offset = vec_scale(hit.normal, 0.001);
	sha.origin = vec_add(hit.point, offset);
	sha.dir = vec_sub(l->pos, sha.origin);
	length = vec_length(sha.dir);
	sha.dir = vec_normalize(sha.dir);
	block = get_closest_hit(scene, &sha);
	if (block.t > 0.001 && block.t < length)
		return (1);
	return (0);
}
