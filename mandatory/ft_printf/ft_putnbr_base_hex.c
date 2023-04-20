/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:15:58 by oaboudan          #+#    #+#             */
/*   Updated: 2022/11/29 18:34:06 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_hex(unsigned int n)
{
	int		len;
	char	*base;

	base = "0123456789ABCDEF";
	len = 0;
	if (n > 15)
	{
		len += ft_putnbr_base_hex(n / 16);
		len += write(1, &base[n % 16], 1);
	}
	else
		len += write(1, &base[n], 1);
	return (len);
}
