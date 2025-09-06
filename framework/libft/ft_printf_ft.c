/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:08:53 by mmillhof          #+#    #+#             */
/*   Updated: 2025/06/02 20:38:21 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	size_t	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putnbr_i(long int nbr)
{
	static size_t	i;
	size_t			sign;

	i = 0;
	sign = 0;
	if (nbr < 0)
	{
		sign = ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_i(nbr / 10);
	i += sign;
	i += write(1, &"0123456789"[nbr % 10], 1);
	return (i);
}

int	ft_putnbr_hex(unsigned long nbr, char *base)
{
	static size_t	i;

	i = 0;
	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16, base);
	i += write(1, &base[nbr % 16], 1);
	return (i);
}

int	ft_putptr(unsigned long ptr)
{
	size_t	chars;

	if (!ptr)
		chars = ft_putstr("(nil)");
	else
	{
		chars = ft_putstr("0x");
		chars += ft_putnbr_hex(ptr, "0123456789abcdef");
	}
	return (chars);
}
