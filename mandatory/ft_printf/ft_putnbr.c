/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:44:10 by oaboudan          #+#    #+#             */
/*   Updated: 2022/11/27 01:03:07 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	a;
	char	c;
	int		len;

	a = n;
	len = 0;
	if (a < 0)
	{
		len += write(1, "-", 1);
		a *= -1;
	}
	if (a >= 0 && a <= 9)
	{
		c = a + '0';
		len += write(1, &c, 1);
	}
	else
	{
		len += ft_putnbr(a / 10);
		len += ft_putchar(((a % 10) + '0'));
	}
	return (len);
}
