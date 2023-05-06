/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:03:31 by oaboudan          #+#    #+#             */
/*   Updated: 2023/05/06 18:33:12 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	int		fd;

	if (ac != 2)
		ft_puterror("Error\nUSAGE:<Executable> <Path/To/Map>\n");
	ft_memset(&vars, 0, sizeof(t_vars));
	args_eroor(ac, av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_puterror("Eroor\ninvalid file\n");
	parse_map(fd, &vars);
	vars.mlx = mlx_init();
	raise_ptr_error(&vars, vars.mlx);
	vars.win = mlx_new_window(vars.mlx, (vars.width - 1)
			* 60, vars.height * 60, SO_LONG);
	raise_ptr_error(&vars, vars.win);
	import_img_assets(&vars);
	put_imgs_map(&vars);
	mlx_hook(vars.win, 2, 0, game_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_exit, &vars);
	mlx_loop(vars.mlx);
}
