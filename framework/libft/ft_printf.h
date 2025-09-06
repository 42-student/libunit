/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:28:29 by mmillhof          #+#    #+#             */
/*   Updated: 2025/06/02 20:39:38 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_printf(const char *fmt, ...);
int	ft_putchar(unsigned char c);
int	ft_putstr(const char *s);
int	ft_putnbr_hex(unsigned long nbr, char *base);
int	ft_putnbr_i(long int nbr);
int	ft_putptr(unsigned long ptr);

#endif
