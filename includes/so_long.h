/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:02:31 by oaboudan          #+#    #+#             */
/*   Updated: 2023/03/27 02:41:28 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_map
{
	char			*row;
	struct s_map	*next;
} t_map;

typedef	struct s_vars
{
	t_map	*map_list;
	void	*mlx;
	void	*win;
	char 	*line;
	char 	**map;
	char	**map2;
	int		width;
	int		height;
	int		coin;
	int		p_x;
	int		p_y;
	int		exit;
}	t_vars;

void	parse_map(int fd, t_vars *vars);
void 	check_map(t_vars *vars);
void	check_border_and_characters(t_vars	*vars);
void	check_valid_path(t_vars *vars);


// utils:
t_map	*ft_new(char *data);
void	add_back(t_map **map, t_map *new);
void	clear_map_list(t_map **map);
void	clear_map2d(char **map);
void	ft_puterror(char *err);




#endif