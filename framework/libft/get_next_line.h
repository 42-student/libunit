/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:55:24 by mmillhof          #+#    #+#             */
/*   Updated: 2025/05/25 15:17:54 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_malloc_init(char *mem[], char **line, char **buf, int fd);
int		ft_search_line(char *mem, char **line, char *buf, int fd);
int		ft_addtoline(char **line, char *buf);
size_t	ft_strcat_nl(char *dst, char *src);
void	ft_strcpy_end(char *dst, char *src);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

#endif
