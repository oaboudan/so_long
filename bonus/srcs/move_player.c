/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:56:33 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/20 02:42:58 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_exit(t_vars *vars, char *mssg)
{
	clear_vars(vars, mssg);
	return (0);
}

int	ft_exit_oc(t_vars *vars)
{
	clear_vars(vars, "Game Quit!!!");
	return (0);
}

int	end_game(t_vars *vars)
{
	ft_printf("You won!\n");
	clear_vars(vars, NULL);
	exit(0);
	return (0);
}

void	move_player(t_vars *vars, int nr, int nc)
{
	if (vars->map[vars->p_x + nr][vars->p_y + nc] == '1')
		return ;
	else if (vars->map[vars->p_x + nr][vars->p_y + nc] == 'C')
		vars->coin--;
	else if (vars->map[vars->p_x + nr][vars->p_y + nc] == 'X')
		ft_exit(vars, "You lose!!\n");
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
	++vars->moves;
	mlx_clear_window(vars->mlx, vars->win);
	put_imgs_map(vars, ' ');
}

int	game_hook(int key, t_vars *vars)
{
	int	nr;
	int	nc;

	if (key == 53)
		clear_vars(vars, "Game Quit !\n");
	else if (key == 126 || key == 123 || key == 124 || key == 125)
	{
		nr = (key == 126) * (-1) + (key == 125) * 1;
		nc = (key == 123) * (-1) + (key == 124) * 1;
		if (key == 124 || key == 123)
			vars->face = key;
		move_player(vars, nr, nc);
	}
	return (1);
}
