/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:14:38 by oaboudan          #+#    #+#             */
/*   Updated: 2023/03/27 01:19:24 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_l(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n' )
		i++;
	line = ft_substr(str, 0, i + 1);
	return (line);
}

char	*next_line(char *str)
{
	int		i;
	char	*next;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	next = ft_substr(str, i + 1, ft_strlen(str + i + 1));
	if (!next)
		return (NULL);
	free (str);
	str = NULL;
	return (next);
}

char	*read_line(char *str, int fd)
{
	char	*buffer;
	ssize_t	read_ret;

	read_ret = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buffer);
			buffer = NULL;
			return (free(str), str = NULL, NULL);
		}
		buffer[read_ret] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	buffer = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = read_line(str, fd);
	if (!str)
		return (NULL);
	line = get_l(str);
	str = next_line(str);
	return (line);
}
