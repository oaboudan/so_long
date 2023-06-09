/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:39:04 by oaboudan          #+#    #+#             */
/*   Updated: 2023/05/06 19:19:37 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_imgs_map(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x])
		{
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->bw, x * 60, y * 60);
			else if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx,
					vars->win, vars->fs, x * 60, y * 60);
			else if (vars->map[y][x] == 'E')
				put_exit_img(vars, x, y);
			else if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx,
					vars->win, vars->col, x * 60, y * 60);
			else
				put_player_img(vars, x, y);
		}
	}
}

void	put_exit_img(t_vars *vars, int x, int y)
{
	if (vars->coin)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->ext_c, x * 60, y * 60);
	else
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->ext_o, x * 60, y * 60);
}

void	put_player_img(t_vars *vars, int x, int y)
{
	if (vars->face == 2)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->pl_r, x * 60, y * 60);
	else
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->pl_l, x * 60, y * 60);
}
