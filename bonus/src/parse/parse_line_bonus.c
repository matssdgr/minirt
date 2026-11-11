/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:16:03 by amine             #+#    #+#             */
/*   Updated: 2026/10/31 14:29:05 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing_bonus.h"

static void normalize_line(char *line)
{
    while (*line)
    {
        if (*line >= 9 && *line <= 13)
            *line = ' ';
        line++;
    }
}

static const char   *dispatch(char **t, t_parser *p)
{
    if (!t[0])
        return (NULL);
    if (!ft_strncmp(t[0], "A", 2))
        return (parse_ambient(t, p));
    if (!ft_strncmp(t[0], "C", 2))
        return (parse_camera(t, p));
    if (!ft_strncmp(t[0], "L", 2))
        return (parse_light(t, p));
    if (!ft_strncmp(t[0], "sp", 2))
        return (parse_sphere(t, p));
    if (!ft_strncmp(t[0], "pl", 2))
        return (parse_plane(t, p));
    if (!ft_strncmp(t[0], "cy", 2))
        return (parse_cylinder(t, p));
    return ("unknown identifier");
}

const char  *parse_line(char *line, t_parser *p)
{
    char        **t;
    const char  *err;

    normalize_line(line);
    t = ft_split(line, ' ');
    if (!t)
        return ("malloc failed");
    err = dispatch(t, p);
    free_split(t);
    return (err);
}
