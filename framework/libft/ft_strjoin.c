/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:11:39 by mmillhof          #+#    #+#             */
/*   Updated: 2025/05/18 13:24:54 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc ((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy (str, s1, s1_len + 1);
	ft_strlcat (str, s2, s1_len + s2_len + 1);
	return (str);
}
