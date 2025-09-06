/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:54:13 by mmillhof          #+#    #+#             */
/*   Updated: 2025/05/23 13:29:13 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		if ((unsigned char)s[i++] == (unsigned char)c)
			return ((char *)&s[i - 1]);
	if ((char)c == 0)
		return ((char *)&s[i]);
	return (NULL);
}
