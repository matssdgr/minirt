/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:46:43 by amine             #+#    #+#             */
/*   Updated: 2026/11/09 12:45:56 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../mlx/mlx_app.h"
# include "../libft_utils/libft_utils.h"

int main(int ac, char **av)
{
    t_app   app;
    
    if (ac != 2)
    {
        ft_putstr_fd("Error\nusage: ./miniRT scene.rt\n", 2);
        return (1);
    }
    ft_bzero(&app, sizeof(t_app));
    if (!parse_file(av[1], &app.scene))
        return (1);
    if (!init_app(&app))
    {
        destroy_app(&app);
        ft_putstr_fd("Error\nMinilibx initialization failed\n", 2);
        return (1);
    }
    setup_hooks(&app);
    render_placeholder(&app);
    mlx_put_image_to_window(app.mlx, app.win, app.img.ptr, 0, 0);
    mlx_loop(app.mlx);
    return (0);
}
