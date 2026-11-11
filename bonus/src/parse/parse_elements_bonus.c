/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:34:12 by amine             #+#    #+#             */
/*   Updated: 2026/11/11 19:53:09 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing_bonus.h"

const char	*parse_ambient(char **t, t_parser *p)
{
	if (p->has_ambient)
		return ("ambient light declared twice");
	if (split_len(t) != 3)
		return ("ambient: expected 'A ratio R,G,B'");
	if (!parse_ranged(t[1], 0, 1, &p->scene->ambient_ratio))
		return ("ambient: ratio must be in [0.0,1.0]");
	if (!parse_color(t[2], &p->scene->ambient_color))
		return ("ambient: invalid color (R,G,B in [0-255])");    
	p->has_ambient = 1;
	return (NULL);
}

const char  *parse_camera(char **t, t_parser *p)
{
    if (p->has_camera)
        return ("Camera declared twice");
    if (split_len(t) != 4)
        return ("camera: expected 'C x,y,z dx,dy,dz fov'");
    if (!parse_vec3(t[1], &p->scene->cam.pos))
        return ("camera: invalid position");
    if (!parse_dir(t[2], &p->scene->cam.dir))
        return ("camera: invalid orientation ([-1,1], not null)");
    if (!parse_ranged(t[3], 0, 180, &p->scene->cam.fov))
        return ("camera: FOV must be in [0, 180]");
    p->has_camera = 1;
    return (NULL);
}

static const char 	*add_light(t_parser *p, t_light *tmp)
{
	t_light *l;

	l = malloc(sizeof(t_light));
	if (!l)
		return ("malloc failed");
	*l = *tmp;
	l->next = p->scene->lights;
	p->scene->lights = l;
	p->has_light = 1;
	return (NULL);
}

const char  *parse_light(char **t, t_parser *p)
{
    t_light	l;

	if (split_len(t) != 3 && split_len(t) != 4)
		return ("light: expected 'L x,y,z brightness [R,G,B]'");
	if (!parse_vec3(t[1], &l.pos))
		return ("light: invalid position");
	if (!parse_ranged(t[2], 0, 1, &l.ratio))
		return ("light: brightness must be in [0.0,1.0]");
	l.color.x = 255;
	l.color.y = 255;
	l.color.z = 255;
	if (t[3] && !parse_color(t[3], &l.color))
		return ("light: invalid color");
	return (add_light(p, &l));
}
