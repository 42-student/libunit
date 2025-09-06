/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:04:32 by mmillhof          #+#    #+#             */
/*   Updated: 2025/05/23 12:18:11 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count(long int n, size_t *pos);
static void	ft_fill(long int n, char *asc, size_t *pos);

char	*ft_itoa(int n)
{
	char		*asc;
	size_t		pos;
	size_t		len;
	long int	nbr;

	nbr = (long int)n;
	pos = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		pos++;
	}
	len = 0;
	ft_count(nbr, &len);
	asc = malloc((len + pos + 1) * sizeof(char));
	if (!asc)
		return (NULL);
	asc[0] = '-';
	ft_fill(nbr, asc, &pos);
	asc[pos] = '\0';
	return (asc);
}

static void	ft_count(long int n, size_t *len)
{
	if (n > 9)
		ft_count(n / 10, len);
	*len = *len + 1;
	return ;
}

static void	ft_fill(long int n, char *asc, size_t *pos)
{
	if (n > 9)
		ft_fill(n / 10, asc, pos);
	asc[*pos] = (n % 10) + '0';
	*pos = *pos + 1;
	return ;
}
