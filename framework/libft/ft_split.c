/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:24:42 by mmillhof          #+#    #+#             */
/*   Updated: 2025/05/22 14:04:22 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_splits(char const *s, char c);
static int	ft_copy_splits(char **arr, char const *s, char c);
static void	free_arr(char **arr, size_t idx);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		idx;

	arr = malloc((ft_find_splits(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	idx = ft_copy_splits (arr, s, c);
	if (idx != -1)
	{
		free_arr(arr, idx);
		free(arr);
		return (NULL);
	}
	return (arr);
}

static int	ft_copy_splits(char **arr, char const *s, char c)
{
	int		found;
	size_t	pos;
	size_t	idx;

	found = -1;
	pos = 0;
	idx = 0;
	while (1)
	{
		if (s[pos] != c && found == -1)
			found = pos;
		else if ((s[pos] == c || s[pos] == '\0') && found >= 0)
		{
			arr[idx] = ft_substr(s, found, pos - found);
			if (!arr[idx])
				return (idx);
			found = -1;
			idx++;
		}
		if (!s[pos])
			break ;
		pos++;
	}
	arr[idx] = NULL;
	return (-1);
}

static int	ft_find_splits(char const *s, char c)
{
	int		found;
	size_t	pos;
	size_t	idx;

	found = -1;
	pos = 0;
	idx = 0;
	while (1)
	{
		if (s[pos] != c && found == -1)
			found = pos;
		else if ((s[pos] == c || s[pos] == '\0') && found >= 0)
		{
			found = -1;
			idx++;
		}
		if (!s[pos])
			break ;
		pos++;
	}
	return (idx);
}

static void	free_arr(char **arr, size_t idx)
{
	size_t	i;

	i = 0;
	while (i <= idx)
	{
		free(arr[i]);
		i++;
	}
	return ;
}
