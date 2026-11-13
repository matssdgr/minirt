/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:46:43 by amine             #+#    #+#             */
/*   Updated: 2026/11/13 20:17:14 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_utils/libft_utils.h"
#include "../mlx/mlx_app.h"

int	main(int ac, char **av)
{
	t_app	app;

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
	init_camera(&app.scene.cam);
	render_scene(&app, &app.scene.cam);
	setup_hooks(&app);
	mlx_put_image_to_window(app.mlx, app.win, app.img.ptr, 0, 0);
	mlx_loop(app.mlx);
	return (0);
}
