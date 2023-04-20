/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:15:09 by oaboudan          #+#    #+#             */
/*   Updated: 2022/11/27 01:22:40 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_x(unsigned long n)
{
	int		len;
	char	*base;

	base = "0123456789abcdef";
	len = 0;
	if (n > 15)
	{
		len += ft_putnbr_base_x(n / 16);
		len += write(1, &base[n % 16], 1);
	}
	else
		len += write(1, &base[n], 1);
	return (len);
}
