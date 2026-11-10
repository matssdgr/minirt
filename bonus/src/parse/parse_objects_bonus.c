/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:56:09 by amine             #+#    #+#             */
/*   Updated: 2026/10/29 12:26:01 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"

static const char   *add_object(t_parser *p, t_object *tmp)
{
    t_object    *o;

    o = malloc(sizeof(t_object));
    if (!o)
        return ("malloc failed");
    *o = *tmp;
    o->next = p->scene->objects;
    p->scene->objects = o;
    return (NULL);
}

const char  *parse_sphere(char **t, t_parser *p)
{
    t_object    o;
    double      diameter;

    if (split_len(t) != 4)
        return ("sphere: expected 'sp x,y,z diameter R,G,B'");
    ft_bzero(&o, sizeof(t_object));
    o.type = SPHERE;
    if (!parse_vec3(t[1], &o.pos))
        return ("sphere: invalid center");
    if (!parse_positive(t[2], &diameter))
        return ("sphere: diameter must be > 0");
    o.radius = diameter / 2;
    if (!parse_color(t[3], &o.color))
        return ("sphere: invalid color");
    return (add_object(p, &o));
}

const char  *parse_plane(char **t, t_parser *p)
{
    t_object    o;
    
    if (split_len(t) != 4)
        return ("plane: expected 'pl x,y,z nx,ny,nz R,G,B'");
    ft_bzero(&o, sizeof(t_object));
    o.type = PLANE;
    if (!parse_vec3(t[1], &o.pos))
        return ("plane: invalid point");
    if (!parse_dir(t[2], &o.dir))
        return ("plane: invalid normal ([-1,1], not null)");
    if (!parse_color(t[3], &o.color))
        return ("plane: invalid color");
    return (add_object(p, &o));
}

const char  *parse_cylinder(char **t, t_parser *p)
{
    t_object    o;
    double      diameter;

    if (split_len(t) != 6)
        return ("cylinder: expected 'cy x,y,z ax,ay,az diameter height RGB'");
    ft_bzero(&o, sizeof(t_object));
    o.type = CYLINDER;
    if (!parse_vec3(t[1], &o.pos))
        return ("cylinder: invalid center");
    if (!parse_dir(t[2], &o.dir))
        return ("cylinder: invalid axis ([-1,1], not null)");
    if (!parse_positive(t[3], &diameter))
        return ("cylinder: diameter must be > 0");
    o.radius = diameter / 2;
    if (!parse_positive(t[4], &o.height))
        return ("cylinder: height must be > 0");
    if (!parse_color(t[5], &o.color))
        return ("cylinder: invalid color");
    return (add_object(p, &o));
}
