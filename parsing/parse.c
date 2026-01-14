/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:20:56 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/13 21:37:45 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	chek_file_extention(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = (int)ft_strlen(s1) - 1;
	len2 = (int)ft_strlen(s2) - 1;
	while (len1 >= 0 || len2 >= 0)
	{
		if (s1[len1] != s2[len2])
			ft_error("Error: Invalid extention", NULL, NULL);
		if (len2 == 0)
		{
			if (s1[len1 - 1] && s1[len1 - 1] != '/')
				return ;
			else
				ft_error("Error: Invalid extention", NULL, NULL);
		}
		len1--;
		len2--;
	}
}

t_elements	*pase_elemetns(int fd)
{
	t_elements	*elm;
	char		*line;

	elm = init_elm();
	elm->fd = fd;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
		{
			hundle_elem(elm, line);
			if (elm->paths == 6)
			{
				free(line);
				break ;
			}
		}
		free(line);
	}
	parse_map(fd, elm);
	chek_map(elm);
	return (elm);
}

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

int	*dup_color(char *line)
{
	char	*tmp;
	char	**str;
	int		*arr;

	arr = malloc(3 * sizeof(int));
	tmp = dup_elm(line);
	str = ft_split(tmp, ',');
	free(tmp);
	if (get_size(str) != 3)
		return (NULL);
	arr[0] = color_atoi(str[0]);
	arr[1] = color_atoi(str[1]);
	arr[2] = color_atoi(str[2]);
	free_map(str);
	if (arr[0] == -1 || arr[1] == -1 || arr[2] == -1)
		return (free(arr),NULL);
	return (arr);
}
