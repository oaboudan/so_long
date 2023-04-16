/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:43:43 by oaboudan          #+#    #+#             */
/*   Updated: 2022/11/27 01:31:15 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int	ft_putnbr_base_x(unsigned long n);
int	ft_putnbr_base_hex(unsigned int n);
int	ft_putchar(int c);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	ft_putstr(char *s);
int	ft_printf(const char *s, ...);
int	check(va_list args, char n);

#endif