/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 19:00:04 by mgoguely          #+#    #+#             */
/*   Updated: 2026/11/13 20:21:48 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	get_mlx_color(t_vec3 color)
{
	int	rgb;

	rgb = (int)color.x << 16 | (int)color.y << 8 | (int)color.z;
	return (rgb);
}
