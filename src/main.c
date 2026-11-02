/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:46:43 by amine             #+#    #+#             */
/*   Updated: 2026/11/02 10:39:20 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"
# include "parsing.h"

int main(int ac, char **av)
{
    t_scene scene;

    if (ac != 2)
    {
        ft_putstr_fd("Error\nusage: ./miniRT scene.rt\n", 2);
        return (1);
    }
    if (!parse_file(av[1], &scene))
        return (1);
    ft_putstr_fd("Scene parsed successfully\n", 1);
    free_scene(&scene);
    return (0);
}
