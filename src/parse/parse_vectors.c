/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:38:00 by amine             #+#    #+#             */
/*   Updated: 2026/11/06 08:07:24 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"

static int  is_byte(double d)
{
    return (d >= 0 && d <= 255 && d == (int)d);
}

int parse_vec3(const char *s, t_vec3 *v)
{
    char    **t;
    int     ok;

    if (count_char(s, ',') != 2)
        return (0);
    t = ft_split(s, ',');
    if (!t)
        return (0);
    ok = (split_len(t) == 3 && parse_double(t[0], &v->x) && parse_double(t[1], &v->y) && parse_double(t[2], &v->z));
    free_split(t);
    return (ok);
}

int parse_color(const char *s, t_vec3 *c)
{
    t_vec3  v;

    if (!parse_vec3(s, &v))
        return (0);
    if (!is_byte(v.x) || !is_byte(v.y) || !is_byte(v.z))
        return (0);
    *c = v;
    return (1);
}

int parse_dir(const char *s, t_vec3 *v)
{
    t_vec3  tmp;

    if (!parse_vec3(s, &tmp))
        return (0);
    if (fabs(tmp.x) > 1 || fabs(tmp.y) > 1 || fabs(tmp.z) > 1)
        return (0);
    if (vec_length(tmp) < 1e-6)
        return (0);
    *v = vec_normalize(tmp);
    return (1);
}
