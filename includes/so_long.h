/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:02:31 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/13 02:22:43 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#define SO_LONG "Collect and Evade"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"

typedef struct s_map
{
	char			*row;
	struct s_map	*next;
} t_map;

typedef	struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*bw;
	void	*fs;
	void	*col;
	void	*pl;
	void	*pl_r;
	void	*pl_l;
	void	*pl_u;
	void	*pl_d;
	void	*ext_o;
	void	*ext_c;
	/// @brief //
	t_map	*map_list;
	char 	*line;
	char 	**map;
	char	**map2;
	int		width;
	int		height;
	int		coin;
	int		p_x;
	int		p_y;
	int		exit;
	int		moves;
}	t_vars;

void	import_img_assets(t_vars *vars);
void	put_imgs_map(int keycode, t_vars *vars);
void	put_exit_img(t_vars *vars,int x, int y);
void	put_player_img(t_vars *vars, int x, int y, int keycode);
void	raise_ptr_error(void *ptr);
void	raise_ptr_error(void *ptr);
void	parse_map(int fd, t_vars *vars);
void 	check_map(t_vars *vars);
void	check_border_and_characters(t_vars	*vars);
//void	check_valid_path(t_vars *vars);
int    ft_backt(char **map, int i, int j, int k);
void	args_eroor(int nbr,char *av);
// utils:
t_map	*ft_new(char *data);
void	add_back(t_map **map, t_map *new);
void	clear_map_list(t_map **map);
void	clear_map2d(char **map);
void	ft_puterror(char *err);




#endif