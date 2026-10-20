/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 23:11:26 by mgoguely          #+#    #+#             */
/*   Updated: 2026/09/25 16:00:42 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define PI 3.14159265358979323846

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_obj_type;

typedef struct s_light
{
	t_vec3			pos;
	t_vec3			color;
	double			ratio;
}	t_light;

typedef struct s_object
{
	t_obj_type		type;
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			color;

	double			radius;
	double			height;

	struct s_object	*next;
}	t_object;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	right;
	t_vec3	up;
	t_vec3	up_left;
	t_vec3	pixel_delta_x;
	t_vec3	pixel_delta_y;
	double	fov;
	double	width;
	double	height;
}	t_camera;

typedef struct s_scene
{
	t_camera	cam;
	t_vec3		ambient_color;
	double		ambient_ratio;

	t_light		light;
	t_object	*objects;
}	t_scene;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

typedef struct s_hit
{
	double		t;
	t_vec3		point;
	t_vec3		normal;
	t_object	*object;
}	t_hit;

t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_scale(t_vec3 v, double scale);
double	vec_length(t_vec3 v);
t_vec3	vec_normalize(t_vec3 v);
double	vec_dot(t_vec3 a, t_vec3 b);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);
t_vec3	ray_at(t_ray ray, double t);
t_vec3	vec_multiply(t_vec3 a, t_vec3 b);
t_vec3	norm_color(t_vec3 color);
double	light(t_scene scene, t_hit hit);
t_vec3	calc_ambient(t_scene scene);
t_vec3	calc_diffuse(t_scene scene, double pl);
t_vec3	get_final_color(t_hit hit, t_scene scene, double pl);
int		get_mlx_color(t_vec3 color);
double	hit_sphere(t_object sphere, t_ray ray);
t_vec3	sphere_normale(t_object sphere, t_vec3 hit_point);
int		impact_point(t_object *sphere, t_ray ray, t_hit *hit);
int		shadow(t_scene scene, t_hit hit, t_ray *shadow);
double	hit_plane(t_object plane, t_ray ray);
void	record_hit_plane(t_object *plane, t_ray ray, double t, t_hit *hit);

#endif
