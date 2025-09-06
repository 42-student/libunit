/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:53:03 by mmillhof          #+#    #+#             */
/*   Updated: 2025/06/05 12:33:32 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buf;
	char			*line;
	static char		*mem[256];
	int				ret;

	if (ft_malloc_init(mem, &line, &buf, fd) < 0)
		return (NULL);
	ret = ft_search_line(mem[fd], &line, buf, fd);
	if (ret < 0)
	{
		free(buf);
		free(line);
		free(mem[fd]);
		mem[fd] = NULL;
		return (NULL);
	}
	if (ret == 0)
	{
		ft_strcpy_end(mem[fd], buf);
		free(buf);
	}
	return (line);
}
