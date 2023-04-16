/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:03:31 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/16 18:13:16 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clear_map2d(char **map)
{
	int i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i++] = NULL;
	}
	free(map);
	map = NULL;
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i++] = NULL;
	}
	free(map);
	map = NULL;
}

// void	destroy_images(t_vars *vars)
// {
// 	// if (vars->ext_c)
// 	// 	mlx_destroy_image(vars->mlx, vars->ext_c);
// }

int	end_game(t_vars *vars)
{
	ft_printf("You won!\n");
	// if (vars->map2)
	// 	// free_map()
	// free(vars->map);
	free_map(vars->map);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx,vars->win);
	// mlx_destroy_image()
	// destroy_images(vars);
	exit(0);
}

void	move_player(t_vars *vars, int nr, int nc)
{
	if (vars->map[vars->p_x + nr][vars->p_y + nc] == '1')
		return ;
	else if (vars->map[vars->p_x + nr][vars->p_y + nc] == 'C')
		vars->coin--;
	else if (vars->map[vars->p_x + nr][vars->p_y + nc] == 'E')
	{
		if (vars->coin == 0)
			end_game(vars);
		else
			return ;
	}
	vars->map[vars->p_x + nr][vars->p_y + nc] = 'P';
	vars->map[vars->p_x][vars->p_y] = '0';
	vars->p_x += nr;
	vars->p_y += nc;
	ft_printf("moves : %d\n", ++vars->moves);
	mlx_clear_window(vars->mlx, vars->win);
	put_imgs_map(vars);
}

int	game_hook(int key, t_vars *vars)
{
	int	nr;
	int	nc;

	if (key == 53)
	{
		ft_printf("Game Quit !");
		mlx_destroy_window(vars->mlx,vars->win);
		exit(0);
	}
	else if (key == 126 || key == 123 || key == 124 || key == 125)
	{
		nr = (key == 126) * (-1) + (key == 125) * 1;
		nc = (key == 123) * (-1) + (key == 124) * 1;
		if (key == 124 || key == 123)
			vars->face = key;
		move_player(vars, nr, nc);
	}
	return 1;
}

// void	leaks()
// {
// 	system("leaks game");
// }

int main(int ac, char **av)
{
	t_vars	vars;
	//atexit(leaks);
	ft_memset(&vars, 0, sizeof(t_vars));
	args_eroor(ac,av[1]);
	int fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_puterror("invalid file\n");
	parse_map(fd, &vars);
	vars.mlx = mlx_init();
	raise_ptr_error(&vars, vars.mlx);
	vars.win = mlx_new_window(vars.mlx,(vars.width - 1) * 60,vars.height * 60, SO_LONG);
	raise_ptr_error(&vars, vars.win);
	import_img_assets(&vars);
	put_imgs_map(&vars);
	mlx_hook(vars.win,2, 0, game_hook, &vars);
	mlx_loop(vars.mlx);
}
