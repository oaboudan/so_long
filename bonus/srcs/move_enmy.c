/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enmy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:41:33 by oaboudan          #+#    #+#             */
/*   Updated: 2023/05/05 17:35:42 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_frame(t_vars *vars)
{
	put_imgs_map(vars, 'X');
	vars->frame++;
	if (vars->is_die)
		ft_exit(vars, "You lose");
	if (vars->frame == FRAMES)
		vars->frame = 0;
}

void	ft_sub_move_ennemi(t_vars *vars)
{
	vars->map[vars->e_x][vars->e_y] = '0';
	vars->e_y++;
	vars->map[vars->e_x][vars->e_y] = 'X';
	if (vars->map[vars->e_x][vars->e_y + 1] == 'P')
		vars->is_die = 1;
	if (vars->map[vars->e_x][vars->e_y + 1] != '0'
		&& vars->map[vars->e_x][vars->e_y + 1] != 'P')
		vars->enmy_move = LEFT;
}

int	ft_move_ennemi(t_vars *vars)
{
	if (vars->frame == 0 || vars->frame == FRAMES / 2)
	{
		if (vars->map[vars->e_x][vars->e_y + 1] == '0'
			&& vars->enmy_move == RIGHT)
			ft_sub_move_ennemi(vars);
		else if (vars->map[vars->e_x][vars->e_y - 1] == '0'
			&& vars->enmy_move == LEFT)
		{
			vars->map[vars->e_x][vars->e_y] = '0';
			vars->e_y--;
			vars->map[vars->e_x][vars->e_y] = 'X';
			if (vars->map[vars->e_x][vars->e_y - 1] == 'P')
				vars->is_die = 1;
			if (vars->map[vars->e_x][vars->e_y - 1] != '0'
				&& vars->map[vars->e_x][vars->e_y + 1] != 'P')
				vars->enmy_move = RIGHT;
		}
		if ((vars->map[vars->e_x][vars->e_y + 1] == 'P')
			|| (vars->map[vars->e_x][vars->e_y - 1] == 'P'))
			vars->is_die = 1;
	}
	ft_frame(vars);
	return (0);
}
