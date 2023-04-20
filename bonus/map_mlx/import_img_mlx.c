/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_img_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:12:50 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/20 02:49:16 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	import_img_assets_2(t_vars *vars, int x, int y)
{
	vars->ext_o = mlx_xpm_file_to_image(vars->mlx,
			"bonus/textures/ex_o.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->ext_o));
	vars->pl_l = mlx_xpm_file_to_image(vars->mlx,
			"bonus/textures/pl_l.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->pl_l));
	vars->pl_r = mlx_xpm_file_to_image(vars->mlx,
			"bonus/textures/pl_r.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->pl_r));
	vars->enmy = mlx_xpm_file_to_image(vars->mlx,
			"bonus/textures/enmy.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->enmy));
}

void	import_img_assets(t_vars *vars)
{
	int	x;
	int	y;

	vars->bw = mlx_xpm_file_to_image(vars->mlx,
			"bonus/textures/bw.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->bw));
	vars->fs = mlx_xpm_file_to_image(vars->mlx,
			"bonus/textures/fs.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->fs));
	vars->col = mlx_xpm_file_to_image(vars->mlx,
			"bonus/textures/col.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->col));
	vars->ext_c = mlx_xpm_file_to_image(vars->mlx,
			"bonus/textures/ex_c.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->ext_c));
	import_img_assets_2(vars, x, y);
	check_img(vars);
}
