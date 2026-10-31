/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:28:58 by amine             #+#    #+#             */
/*   Updated: 2026/10/29 16:16:50 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "minirt.h"
# include "libft.h"

typedef struct  s_parser
{
    t_scene *scene;
    int     has_ambient;
    int     has_camera;
    int     has_light;
}   t_parser;

/* parse_split */
int     count_char(const char *s, char c);
int     split_len(char **t);
void    free_split(char **t);

/* parse_numbers */
int     parse_double(const char *s, double *out);
int     parse_ranged(const char *s, double min, double max, double *out);
int     parse_positive(const char *s, double *out);

/* parse_vectors */
int     parse_vec3(const char *s, t_vec3 *v);
int     parse_dir(const char *s, t_vec3 *v);
int     parse_color(const char *s, t_vec3 *c);

/* parse_elements */
const char  *parse_ambient(char **t, t_parser *p);
const char  *parse_camera(char **t, t_parser *p);
const char  *parse_light(char **t, t_parser *p);

/* parse_objects */
const char  *parse_sphere(char **t, t_parser *p);
const char  *parse_plane(char **t, t_parser *p);
const char  *parse_cylinder(char **t, t_parser *p);

/* utils */
void    free_scene(t_scene *s);

#endif