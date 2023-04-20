/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:00:38 by oaboudan          #+#    #+#             */
/*   Updated: 2023/04/20 02:43:21 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	numlength(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	z;

	z = n;
	len = 0;
	str = (char *)malloc(numlength(z)+ 1);
	if (!str)
		return (NULL);
	if (z < 0)
	{
		str[0] = '-';
		z *= -1;
		len++;
	}
	len += numlength(z);
	str[len--] = '\0';
	while (z >= 0)
	{
		str[len--] = z % 10 + '0';
		z = z / 10;
		if (z == 0)
			break ;
	}
	return (str);
}
// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*tab;
// 	int		len_s1;
// 	int		len_s2;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (!s2 || !s1)
// 		return (NULL);
// 	len_s1 = ft_strlen(s1);
// 	len_s2 = ft_strlen(s2);
// 	tab = malloc(((len_s1 + len_s2) + 1));
// 	if (!tab)
// 		exit(1);
// 	while (s1[i])
// 	{
// 		tab[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 		tab[i++] = s2[j++];
// 	return (free(s1), tab[i] = '\0', tab);
// }
