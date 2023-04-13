/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_img_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:12:50 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/13 17:26:35 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	import_img_assets(t_vars *vars)
{
	int x;
	int y;
	
	vars->bw = mlx_xpm_file_to_image(vars->mlx, "././assets/bw.xpm", &x, &y);
	raise_ptr_error(vars->bw);
	vars->fs = mlx_xpm_file_to_image(vars->mlx, "././assets/fs.xpm", &x, &y);
	raise_ptr_error(vars->fs);
	vars->col = mlx_xpm_file_to_image(vars->mlx, "././assets/col.xpm", &x, &y);
	raise_ptr_error(vars->col);
	vars->ext_c = mlx_xpm_file_to_image(vars->mlx, "././assets/ex_c.xpm", &x, &y);
	raise_ptr_error(vars->ext_c);
	vars->ext_o = mlx_xpm_file_to_image(vars->mlx, "././assets/ex_o.xpm", &x, &y);
	raise_ptr_error(vars->ext_o);
	vars->pl_d = mlx_xpm_file_to_image(vars->mlx, "././assets/pl_u.xpm", &x, &y);
	raise_ptr_error(vars->pl_d);
	vars->pl_u = mlx_xpm_file_to_image(vars->mlx, "././assets/pl_d.xpm", &x, &y);
	raise_ptr_error(vars->pl_u);
	vars->pl_l = mlx_xpm_file_to_image(vars->mlx, "././assets/pl_l.xpm", &x, &y);
	raise_ptr_error(vars->pl_l);
	vars->pl_r = mlx_xpm_file_to_image(vars->mlx, "././assets/pl_r.xpm", &x, &y);
	raise_ptr_error(vars->pl_r);
	
}
