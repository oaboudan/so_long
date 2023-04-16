/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_img_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:12:50 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/16 03:57:48 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// typedef struct	s_img
// {
		
// } 

void	check_img(t_vars *vars)
{
	t_col *itr;

	itr  = vars->img_str;
	while (itr)
	{
		if (!itr->img)
			clear_vars(vars, 1);
		itr = itr->next;
	}
}

t_col	*ft_new_img(void *data)
{
	t_col *img;

	img = malloc(sizeof(t_col));
	if (!img)
		return NULL;
	img->img = data;
	img->next = NULL;
	return (img);
}

void	push_img_back(t_col **lst, t_col *new)
{
	t_col	*itr;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	itr = *lst;
	while (itr->next)
		itr = itr->next;
	itr->next = new;
}
void	destroy_images(t_vars *vars, t_col **lst, int (*del)(void *, void *))
{
	t_col	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->img)
			del(vars->mlx, (*lst)->img);
		free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
	*lst = NULL;
}
void	clear_vars(t_vars *vars, int code)
{
	if (vars->map)
		free_map(vars->map);
	if (vars->mlx)
	{
		destroy_images(vars, &vars->img_str, mlx_destroy_image);
		if (vars->win)
		{
			mlx_clear_window(vars->mlx, vars->win);
			mlx_destroy_window(vars->mlx, vars->win);
		}
	}
	if (code)
		ft_puterror("Error\n");
	exit(0);
}
void	import_img_assets(t_vars *vars)
{
	int x;
	int y;
	
	vars->bw = mlx_xpm_file_to_image(vars->mlx, "././assets/bw.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->bw));
	vars->fs = mlx_xpm_file_to_image(vars->mlx, "././assets/fs.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->fs));
	vars->col = mlx_xpm_file_to_image(vars->mlx, "././assets/col.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->col));
	vars->ext_c = mlx_xpm_file_to_image(vars->mlx, "././assets/ex_c.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->ext_c));
	vars->ext_o = mlx_xpm_file_to_image(vars->mlx, "././assets/ex_o.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->ext_o));
	vars->pl_l = mlx_xpm_file_to_image(vars->mlx, "././assets/pl_l.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->pl_l));
	vars->pl_r = mlx_xpm_file_to_image(vars->mlx, "././assets/pl_r.xpm", &x, &y);
	push_img_back(&vars->img_str, ft_new_img(vars->pl_r));
	check_img(vars);
}
