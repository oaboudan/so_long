/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:41:49 by oaboudan          #+#    #+#             */
/*   Updated: 2022/11/29 19:07:54 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(va_list args, char n)
{
	int	len;

	len = 0;
	if (n == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (n == 'd' || n == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (n == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (n == 'u')
		len += ft_putnbr_u(va_arg(args, unsigned int));
	else if (n == 'x')
		len += ft_putnbr_base_x(va_arg(args, unsigned int));
	else if (n == 'X')
		len += ft_putnbr_base_hex(va_arg(args, unsigned int));
	else if (n == 'p')
		len += ft_putstr("0x") + ft_putnbr_base_x(va_arg(args, unsigned long));
	else if (n == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(n);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[++i])
			len += check(args, s[i]);
		else if (!s[i])
			break ;
		else
			len += write(1, &s[i], 1);
		i++;
	}
	if (len < 0)
		return (-1);
	va_end(args);
	return (len);
}
// int main()
// {
// 	fclose(stdout);
// 	int res = ft_printf("%s", "khalid");
// 	fprintf(stderr,"%d",res);
// }