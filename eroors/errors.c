/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:20:04 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/16 03:53:31 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	raise_ptr_error(t_vars *vars, void *ptr)
{
	if(!ptr)
		clear_vars(vars, 1);
}
void	ft_puterror(char *err)
{
	while (*err)
		write(2, err++, 1);
	exit(EXIT_FAILURE);
}

void	args_eroor(int nbr,char *av)
{
	int start;
	char *ext;
	
	start = ft_strlen(av);
	if (!ft_strnstr(av, ".ber", start) || nbr != 2)
		ft_puterror("Error\nunvalid map file.");
	start -= 4;
	ext = ft_substr(av, start, 4);
	if (strcmp(".ber", ext))
	{
		free(ext);
		ft_puterror("Error:\nunvalid map file.");
	}
	free(ext);
}
