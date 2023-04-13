/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:03:31 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/13 18:31:47 by oaboudan         ###   ########.fr       */
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

void	leaks()
{
	system("leaks so_long");
}

void	args_eroor(int nbr,char *av)
{
	int start;
	char *ext;
	
	start = strlen(av);
	if (!strnstr(av, ".ber", start) || nbr != 2)
		ft_puterror("Error\nunvalid map file.");
	start -= 4;
	ext = ft_substr(av, start, 4);
	if (strcmp(".ber", ext))
	{
		free(ext);
		ft_puterror("Error:\nunvalid map file.");
	}
	free(ext);
}

int	end_game(t_vars *vars)
{
	printf("You won!\n");
	free(vars->map);
	mlx_destroy_window(vars->mlx,vars->win);
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
	printf("moves : %d\n", ++vars->moves);
	mlx_clear_window(vars->mlx, vars->win);
	put_imgs_map(13, vars);
}

int	game_hook(int key, t_vars *vars)
{
	int	nr;
	int	nc;

	if (key == 53)
	{
		printf("Game Quit !");
		mlx_destroy_window(vars->mlx,vars->win);
		exit(0);
	}
	else if (key == 126 || key == 123 || key == 124 || key == 125)
	{
		nr = (key == 126) * (-1) + (key == 125) * 1;
		nc = (key == 123) * (-1) + (key == 124) * 1;
		move_player(vars, nr, nc);
	}
	return 1;
}

int main(int ac, char **av)
{
	t_vars	vars;
	// atexit(leaks);
	memset(&vars, 0, sizeof(t_vars));
	args_eroor(ac,av[1]);
	int fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_puterror("invalid file\n");
	parse_map(fd, &vars);
	vars.mlx = mlx_init();
	raise_ptr_error(vars.mlx);
	vars.win = mlx_new_window(vars.mlx,(vars.width - 1) * 60,vars.height * 60, SO_LONG);
	raise_ptr_error(vars.win);
	import_img_assets(&vars);
	put_imgs_map(13,&vars);
	mlx_key_hook(vars.win, game_hook, &vars);
	mlx_loop(vars.mlx);
}

// map[y][x] = map[y - 1][x]












// if (ac == 2)
// 	{
// 		if (!strnstr(av[1], ".ber", strlen(av[1])))
// 		{
// 			ft_puterror("Error\nProgram must take a <.ber> file.");
// 			return (EXIT_FAILURE);
// 		}
// 		int fd = open(av[1], O_RDONLY);
// 		if (fd == -1)
// 			return (printf("invalid file\n"), 1);
// 		else
// 		{
// 			parse_map(fd, &vars);
// 			// TODO:
// 			// so_long(&vars);
// 		}
// 	}
// 	else
// 		printf("Error\n");