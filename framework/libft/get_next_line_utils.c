/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:55:09 by mmillhof          #+#    #+#             */
/*   Updated: 2025/05/25 20:48:01 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_malloc_init(char *mem[], char **line, char **buf, int fd)
{
	if (BUFFER_SIZE < 1 || fd < 0 || fd >= 256 || fd == 1 || fd == 2)
		return (-1);
	if (!mem[fd])
	{
		mem[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!mem[fd])
			return (-2);
		mem[fd][0] = '\0';
	}
	*buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	*line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*line || !*buf)
	{
		if (*buf)
			free(*buf);
		if (*line)
			free(*line);
		free(mem[fd]);
		mem[fd] = NULL;
		return (-3);
	}
	(*line)[0] = '\0';
	return (0);
}

int	ft_search_line(char *mem, char **line, char *buf, int fd)
{
	int	found;
	int	size;

	if (ft_strcat_nl(*line, mem))
	{
		ft_strcpy_end(mem, mem);
		free(buf);
		return (1);
	}
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (-1);
		buf[size] = '\0';
		if (size == 0 && (*line)[0])
			return (0);
		if (size == 0)
			return (-2);
		found = ft_addtoline(line, buf);
		if (found < 0)
			return (-3);
		if (found)
			return (0);
	}
}

int	ft_addtoline(char **line, char *buf)
{
	char	*temp;
	size_t	i;
	size_t	found;

	i = 0;
	while ((*line)[i])
		i++;
	temp = malloc((i + BUFFER_SIZE + 2) * sizeof(char));
	if (!temp)
		return (-1);
	temp[0] = '\0';
	ft_strcat_nl(temp, *line);
	found = ft_strcat_nl(temp, buf);
	free(*line);
	*line = temp;
	if (found)
		return (1);
	return (0);
}

size_t	ft_strcat_nl(char *dst, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j])
	{
		dst[i + j] = src[j];
		if (src[j] == '\n')
		{
			dst[j + i + 1] = '\0';
			return (1);
		}
		j++;
	}
	dst[i + j] = '\0';
	return (0);
}

void	ft_strcpy_end(char *dst, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		i++;
	j = 0;
	while (src[i + j])
	{
		dst[j] = src[i + j];
		j++;
	}
	dst[j] = '\0';
	return ;
}
