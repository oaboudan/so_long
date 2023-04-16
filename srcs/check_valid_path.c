/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:41:00 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/15 22:32:22 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int    ft_backt(char **map, int i, int j, int k)
{
    static int    e;
    static int    c;
    int x =0;
    int y = 0;

    if (map[i][j] == 'E')
    {
        e = 1;
        return (1);
    }
    else if (map[i][j] == 'C')
        c++;
    map[i][j] = '1';
    if (map[i][j + 1] != '1' )
        ft_backt(map, i, j + 1, k);
    if (map[i + 1][j] != '1')
        ft_backt(map, i + 1, j, k);
    if (map[i][j - 1] != '1')
        ft_backt(map, i, j - 1, k);
    if (map[i - 1][j] != '1')
        ft_backt(map, i - 1, j, k);
    if (e && k == c)
        return (1);
    return (0);
}