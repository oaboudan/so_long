/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:25:11 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/15 22:40:24 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return ((void *)b);
}
char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!hay && len == 0)
		return (NULL);
	if (!*hay && !*ndl)
		return ((char *)hay);
	while (hay[i] != '\0')
	{
		while (hay[i + j] == ndl[j] && i + j < len && hay[i + j] != '\0')
			j++;
		if (!ndl[j])
			return ((char *)hay + i);
		i++;
		j = 0;
	}
	return (0);
}