/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:04:40 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/15 18:06:33 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_all(int fd, char *line)
{
	char	*buffer;
	int		index;

	buffer = malloc(2);
	if (!buffer)
		return (free(line), NULL);
	while (1)
	{
		index = read(fd, buffer, 1);
		if (index < 0)
		{
			free(buffer);
			return (free(line), line = NULL, NULL);
		}
		if (index == 0)
			break ;
		buffer[index] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(buffer), NULL);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

char	*get_lin(char *str)
{
	int		i;
	int		j;
	char	*line;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_remain(char *str)
{
	char	*remain;
	char	*dup_remain;

	if (!str)
		return (NULL);
	remain = ft_strchr(str, '\n');
	if (!remain)
		return (NULL);
	if (remain[0] == '\n' && ft_strlen(remain) == 1)
		return (NULL);
	dup_remain = ft_strdup(remain + 1);
	if (!dup_remain)
		return (NULL);
	return (dup_remain);
}

char	*get_next_line(int fd)
{
	static char	*st_str;
	char		*full_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_line = get_all(fd, st_str);
	if (!full_line)
		return (st_str = NULL);
	line = get_lin(full_line);
	if (!line)
		return (st_str = NULL, free(full_line), full_line = NULL, NULL);
	st_str = get_remain(full_line);
	free(full_line);
	return (line);
}
