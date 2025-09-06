/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:09:32 by mmillhof          #+#    #+#             */
/*   Updated: 2025/05/21 12:30:10 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_start(char const *s1, char const *set);
static size_t	ft_find_end(char const *s1, char const *set, size_t end);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	start;
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = ft_find_start(s1, set);
	len = ft_find_end(s1, set, s1_len - 1) - start + 1;
	str = ft_substr(s1, start, len);
	return (str);
}

static size_t	ft_find_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			j++;
		}
		if (set[j] == 0)
			break ;
	}
	return (i);
}

static size_t	ft_find_end(char const *s1, char const *set, size_t end)
{
	size_t	i;

	while (s1[end])
	{
		i = 0;
		while (set[i])
		{
			if (s1[end] == set[i])
			{
				end--;
				break ;
			}
			i++;
		}
		if (set[i] == 0)
			break ;
	}
	return (end);
}
