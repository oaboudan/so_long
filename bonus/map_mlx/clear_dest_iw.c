/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_dest_iw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:20:53 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/20 02:42:24 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_img(t_vars *vars)
{
	t_col	*itr;

	itr = vars->img_str;
	while (itr)
	{
		if (!itr->img)
			clear_vars(vars, "Eroor\nimage allocation faild");
		itr = itr->next;
	}
}

t_col	*ft_new_img(void *data)
{
	t_col	*img;

	img = malloc(sizeof(t_col));
	if (!img)
		return (NULL);
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

void	clear_vars(t_vars *vars, char *err)
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
	if (err)
		ft_puterror(err);
	exit(0);
}
