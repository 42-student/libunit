/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:21:29 by mmillhof          #+#    #+#             */
/*   Updated: 2025/06/02 20:35:48 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_switch(va_list args, const char *fmt);

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		chars;

	if (!fmt)
		return (0);
	va_start(args, fmt);
	chars = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			chars += ft_switch(args, fmt);
		}
		else
			chars += ft_putchar(*fmt);
		fmt++;
	}
	va_end(args);
	return (chars);
}

int	ft_switch(va_list args, const char *fmt)
{
	int				chars;

	chars = 0;
	if (*fmt == '%')
		chars = ft_putchar('%');
	else if (*fmt == 'c')
		chars = ft_putchar(va_arg(args, int));
	else if (*fmt == 's')
		chars = ft_putstr(va_arg(args, const char *));
	else if (*fmt == 'p')
		chars = ft_putptr(va_arg(args, unsigned long));
	else if (*fmt == 'd' || *fmt == 'i')
		chars += ft_putnbr_i(va_arg(args, int));
	else if (*fmt == 'u')
		chars += ft_putnbr_i(va_arg(args, unsigned int));
	else if (*fmt == 'x')
		chars = ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*fmt == 'X')
		chars = ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (chars);
}
