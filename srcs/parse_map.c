/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:13:21 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/15 22:41:29 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


t_map	*ft_new(char *data)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->row = data;
	new->next = NULL;
	return (new);
}

void	add_back(t_map **map, t_map *new)
{
	t_map	*itr;

	if (!map || !new)
		return ;
	if (!*map)
	{
		*map = new;
		return ;
	}
	itr = *map;
	while (itr->next)
		itr = itr->next;
	itr->next = new;
}

void	clear_map_list(t_map **map)
{
	t_map	*itr;

	if (*map || !map)
		return ;
	
	while (*map)
	{
		itr = (*map)->next;
		free((*map)->row);
		(*map)->row = NULL;
		free(*map);
		*map = NULL;
		*map = itr;
	}
	perror("Allocation failed");
	exit(1);
}

void	read_map(int fd, t_vars *vars)
{
	t_map	*itr;
	int		i;

	vars->map_list =  NULL;
	vars->line = get_next_line(fd);
	while (vars->line != NULL)
	{
		add_back(&vars->map_list, ft_new(vars->line));
		vars->height++;
		vars->line = get_next_line(fd);
	}
	vars->map = malloc(sizeof(char *) * vars->height + 1);
	if (!vars->map)
		clear_map_list(&vars->map_list);
	i = 0;
	while (vars->map_list)
	{
		itr = vars->map_list->next;
		vars->map[i++] = vars->map_list->row;
		free(vars->map_list);
		vars->map_list = itr;
	}
	vars->map[i] = NULL;
	close(fd);
}

void	parse_map(int fd, t_vars *vars)
{
	read_map(fd, vars);
	vars->width = ft_strlen(vars->map[0]);
	check_map(vars);
}