/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:33:06 by oaboudan          #+#    #+#             */
/*   Updated: 2023/03/27 02:40:45 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// 1111111111111
// 11010000000C1
// 1000011111001
// 1P0011E000001
// 1111111111111



int	ft_match(char *s1, char *s2)
{
	while (*s1)
	{
		// forbedin func:
		if (!strchr(s2, *s1))
			return (0);
		s1++;
	}
	return (1);
}

void	check_border_and_characters(t_vars	*vars)
{
	int	x;
	int	y;

	x = 0;
	if (!ft_match(vars->map[0], "1\n") 
		|| !ft_match(vars->map[vars->height - 1], "1\n"))
		ft_puterror("error : invalid map\n");
	while (vars->map[x])
	{
		// forb func:
		if (!vars->map[x + 1]
			&& (strlen(vars->map[x])) != (vars->width - 1))
			ft_puterror("error : invalid map\n");
		if (vars->map[x + 1]
			&& strlen(vars->map[x]) != vars->width)
			ft_puterror("error : invalid map\n");
		if (vars->map[x + 1] && 
			(vars->map[x][0] != '1' || vars->map[x][vars->width - 2] != '1'))
			ft_puterror("error : invalid map\n");
		if (!ft_match(vars->map[x], "10PCE\n"))
			ft_puterror("error : invalid map\n");
		x++;
	}
}

void	count_characters(t_vars *vars)
{
	int	x;
	int	y;

	x = -1;
	while (vars->map[++x])
	{
		y = -1;
		while (vars->map[x][++y])
		{
			if (vars->map[x][y] == 'P' && vars->p_x == 0)
			{
				vars->p_x = x;
				vars->p_y = y;
			}
			else if (vars->map[x][y] == 'P' && vars->p_x != 0)
				ft_puterror("error invalid map\n");
			if (vars->map[x][y] == 'C')
				vars->coin++;
			if (vars->map[x][y] == 'E' && vars->exit == 0)
				vars->exit = 1;
			else if (vars->map[x][y] == 'E' && vars->exit != 0)
				ft_puterror("error : invalid map\n");
		}
	}
}

void	check_map(t_vars *vars)
{
	int	x;

	check_border_and_characters(vars);
	count_characters(vars);
	if (!vars->exit || !vars->coin || !vars->p_x)
		ft_puterror("error invalid map\n");
	x = -1;
	vars->map2 = malloc(sizeof(char *) * vars->height + 1);
	if (!vars->map2)
		ft_puterror("Alocation failed\n");
	while (vars->map[++x])
		vars->map2[x] = strdup(vars->map[x]);
	vars->map2[x] = NULL;
	check_valid_path(vars);
}