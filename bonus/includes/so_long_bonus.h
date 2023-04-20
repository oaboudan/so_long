/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:02:31 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/20 02:23:14 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define SO_LONG "Collect and Evade"
# define FRAMES 40
# define RIGHT 0
# define LEFT 1

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <mlx.h>

typedef struct s_map
{
	char			*row;
	struct s_map	*next;
}	t_map;

typedef struct s_img_collector
{
	void					*img;
	struct s_img_collector	*next;
}	t_col;

typedef struct s_vars
{
	t_col	*img_str;
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
	void	*enmy;
	void	*ext_o;
	void	*ext_c;
	t_map	*map_list;
	char	*line;
	char	**map;
	char	**map2;
	int		width;
	int		height;
	int		coin;
	int		p_x;
	int		p_y;
	int		exit;
	int		moves;
	int		face;
	int		enmy_move;
	int		frame;
	int		is_die;
	int		e_x;
	int		e_y;
}	t_vars;

int		ft_move_ennemi(t_vars *vars);
int		ft_exit_oc(t_vars *vars);
int		ft_exit(t_vars *vars, char *mssg);
int		game_hook(int key, t_vars *vars);
void	check_img(t_vars *vars);
t_col	*ft_new_img(void *data);
void	move_player(t_vars *vars, int nr, int nc);
void	import_img_assets(t_vars *vars);
void	put_imgs_map(t_vars *vars, char c);
void	put_exit_img(t_vars *vars, int x, int y);
void	put_player_img(t_vars *vars, int x, int y);
void	raise_ptr_error(t_vars *vars, void *ptr);
void	check_map(t_vars *vars);
void	check_border_and_characters(t_vars	*vars);
void	free_map(char **map);
void	clear_vars(t_vars *vars, char *err);
void	destroy_images(t_vars *vars, t_col **lst, int (*del)(void *, void *));
int		ft_backt(char **map, int i, int j, int k);

void	args_eroor(int nbr, char *av);
// utils:
t_map	*ft_new(char *data);
void	add_back(t_map **map, t_map *new);
void	clear_map_list(t_map **map);
void	clear_map2d(char **map);
void	ft_puterror(char *err);
void	push_img_back(t_col **lst, t_col *new);
void	parse_map(int fd, t_vars *vars);
//libft
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strnstr(const char *hay, const char *ndl, size_t len);
char	*ft_itoa(int n);

#endif