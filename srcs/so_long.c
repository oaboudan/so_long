/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:03:31 by oaboudan          #+#    #+#             */
/*   Updated: 2023/03/27 01:29:58 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clear_map2d(char **map)
{
	int i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i++] = NULL;
	}
	free(map);
	map = NULL;
}

void	leaks()
{
	system("leaks so_long");
}

int main(int ac, char **av)
{
	t_vars	vars;

	// atexit(leaks);
	memset(&vars, 0, sizeof(t_vars));
	if (ac == 2)
	{
		int fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (printf("invalid file\n"), 1);
		else
		{
			parse_map(fd, &vars);
			// TODO:
			// so_long(&vars);
		}
	}
	else
		printf("Error\n");
}