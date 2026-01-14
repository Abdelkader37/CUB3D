/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:22:33 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/14 20:40:33 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_map(int fd, t_elements *elm)
{
	char	*s;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line || line[0] != '\n')
			break ;
		free(line);
	}
	if (!line)
		ft_error("Error: map not found", elm, NULL);
	s = NULL;
	while (1)
	{
		s = ft_strjoin(s, line);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
			return (free(s), ft_error("Error: Invalid map", elm, line));
	}
	chek_symbol(s, elm);
}

void	chek_map(t_elements *elm)
{
	int	x;
	int	y;
	int	size;

	size = get_size(elm->map);
	x = 0;
	y = 0;
	while (elm->map[y])
	{
		x = 0;
		while (elm->map[y][x])
		{
			if (elm->map[y][x] == ' ')
				chek_space(elm, x, y, size);
			else if (str_char(elm->map[y][x], MAP_SYMBOLS))
				chek_player(elm, x, y, size);
			else
			{
				if (elm->map[y][x] != '1')
					ft_error("Error: Invalid map", elm, NULL);
			}
			x++;
		}
		y++;
	}
}

void	chek_space(t_elements *elm, int x, int y, int size)
{
	if (str_char(elm->map[y][x + 1], MAP_SYMBOLS))
		ft_error("Error: Invalid map", elm, NULL);
	if (y + 1 < size && x < (int)ft_strlen(elm->map[y + 1]))
		if (str_char(elm->map[y + 1][x], MAP_SYMBOLS))
			ft_error("Error: Invalid map", elm, NULL);
	if (y - 1 >= 0 && x < (int)ft_strlen(elm->map[y - 1]))
		if (str_char(elm->map[y - 1][x], MAP_SYMBOLS))
			ft_error("Error: Invalid map", elm, NULL);
	if (x > 0)
		if (str_char(elm->map[y][x - 1], MAP_SYMBOLS))
			ft_error("Error: Invalid map", elm, NULL);
}

void	chek_player(t_elements *elm, int x, int y, int size)
{
	if (y == 0 || y == size - 1)
		ft_error("Error: Invalid map", elm, NULL);
	if (elm->map[y][x + 1] == ' ' || !elm->map[y][x + 1])
		ft_error("Error: Invalid map", elm, NULL);
	if (y + 1 < size)
		if (x >= (int)ft_strlen(elm->map[y + 1]) || elm->map[y + 1][x] == ' '
			|| y + 1 >= size || !elm->map[y + 1][x])
			ft_error("Error: Invalid map", elm, NULL);
	if (y - 1 >= 0 && x <= (int)ft_strlen(elm->map[y - 1]))
		if (!elm->map[y - 1][x] || elm->map[y - 1][x] == ' ' || y - 1 < 0)
			ft_error("Error: Invalid map", elm, NULL);
	if (x - 1 < 0 || elm->map[y][x - 1] == ' ')
		ft_error("Error: Invalid map", elm, NULL);
}

void	chek_symbol(char *map, t_elements *elm)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (map[i])
	{
		if (str_char(map[i], PLAYER_SYMBOLS))
			cnt++;
		i++;
	}
	if (cnt != 1)
		ft_error("Error: Invalid map", elm, map);
	elm->map = ft_split(map, '\n');
	free(map);
}
