/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:08:58 by amine             #+#    #+#             */
/*   Updated: 2026/10/31 14:41:22 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"

static int  print_error(const char *msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd((char *)msg, 2);
    ft_putstr_fd("\n", 2);
    return (0);
}

static int  has_rt_extension(const char *path)
{
    size_t  len;
    
    len = ft_strlen(path);
    return (len > 3 && !ft_strncmp(path + len - 3, ".rt", 4));
}

static const char   *read_line(int fd, t_parser *p)
{
    char        *line;
    const char  *err;

    err = NULL;
    line = get_next_line(fd);
    while (line)
    {
        if (!err)
            err = parse_line(line, p);
        free(line);
        line = get_next_line(fd);
    }
    return (err);
}

int parse_file(const char *path, t_scene *scene)
{
    t_parser    p;
    int         fd;
    const char  *err;

    ft_bzero(scene, sizeof(t_scene));
    ft_bzero(&p, sizeof(t_parser));
    p.scene = scene;
    if (!has_rt_extension(path))
        return (print_error("file must have a .rt extension"));
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (print_error(strerror(errno)));
    err = read_line(fd, &p);
    close(fd);
    if (!err && !(p.has_ambient && p.has_camera && p.has_light))
        err = "missing element: A, C and L are required";
    if (err)
    {
        free_scene(scene);
        return (print_error(err));
    }
    return (1);
}
