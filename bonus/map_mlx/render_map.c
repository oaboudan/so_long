/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:39:04 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/20 02:42:34 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	sub_put_imgs_map(t_vars *vars, int x, int y, char c)
{
	if (vars->map[y][x] == '1' && c == ' ')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->bw, x * 60, y * 60);
	else if (vars->map[y][x] == '0' && (c == ' ' || c == 'X'))
		mlx_put_image_to_window(vars->mlx,
			vars->win, vars->fs, x * 60, y * 60);
	else if (vars->map[y][x] == 'E' && c == ' ')
		put_exit_img(vars, x, y);
	else if (vars->map[y][x] == 'C' && c == ' ')
		mlx_put_image_to_window(vars->mlx,
			vars->win, vars->col, x * 60, y * 60);
	else if (vars->map[y][x] == 'X' && (c == ' ' || c == 'X'))
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->enmy, x * 60, y * 60);
	else if (vars->map[y][x] == 'P' && c == ' ')
		put_player_img(vars, x, y);
}

void	put_imgs_map(t_vars *vars, char c)
{
	int		x;
	int		y;
	char	*str;
	char	*ptr;

	y = -1;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x])
			sub_put_imgs_map(vars, x, y, c);
	}
	ptr = ft_itoa(vars->moves);
	str = ft_strjoin(ft_strdup("Movement: "), ptr);
	free(ptr);
	mlx_string_put(vars->mlx, vars->win, 20, 20, 0xFFFFFF, str);
	free(str);
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
	if (vars->face == 124)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->pl_r, x * 60, y * 60);
	else
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->pl_l, x * 60, y * 60);
}
