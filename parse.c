/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:20:56 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/08 18:23:03 by aqrafi           ###   ########.fr       */
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
		{
			printf("error\n");
			exit(1);
		}
		if (len2 == 0)
		{
			if (s1[len1 - 1] && s1[len1 - 1] != '/')
				return ;
			else
			{
				printf("error \n");
				exit(1);
			}
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
	elm->map = parse_map(fd);
	chek_map(elm->map);
	return (elm);
}



char	**parse_map(int fd)
{
	char	**map;
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
	{
		write(2, "Error: map not found\n", 21);
		exit(1);
	}
	s = NULL;
	while (1)
	{
		s = ft_strjoin(s, line);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			write(2, "Error: Invalid map\n", 20);
			exit(1);
		}
	}
	chek_symbol(s);
	map = ft_split(s, '\n');
	return (free(s), map);
}

void	chek_map(char **map)
{
	int	x;
	int	y;
	int	size;

	size = get_size(map);
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == ' ')
				chek_space(map, x, y, size);
			else if (str_char(map[y][x], MAP_SYMBOLS))
				chek_player(map, x, y, size);
			else
			{
				if (map[y][x] != '1')
				{
					write(2, "Error: Invalid map\n", 20);
					exit(1);
				}
			}
			x++;
		}
		y++;
	}
}

void	chek_space(char **map, int x, int y, int size)
{
	if (str_char(map[y][x + 1], MAP_SYMBOLS))
		write(2, "Error: 0Invalid map\n", 20);
	if (y + 1 < size  && x < (int)ft_strlen(map[y + 1]))
		if (str_char(map[y + 1][x],MAP_SYMBOLS))
			write(2, "Error: 1Invalid map\n", 20);
	if (y - 1 >= 0 && x < (int)ft_strlen(map[y - 1]))
		if (str_char(map[y - 1][x],MAP_SYMBOLS))
			write(2, "Error: 2Invalid map\n", 20);
	if(x > 0)
		if (str_char(map[y][x - 1], MAP_SYMBOLS))
			write(2, "Error: 3Invalid map\n", 20);
}

void	chek_player(char **map, int x, int y, int size)
{
	if (y == 0 || y == size - 1)
		write(2, "Error: 1Invalid map\n", 20);
	if (map[y][x + 1] == ' ' || !map[y][x + 1])
		write(2, "Error: 2Invalid map\n", 20);
	if (y + 1 < size)
		if (x >= (int)ft_strlen(map[y + 1]) || map[y + 1][x] == ' ' || y
			+ 1 >= size || !map[y + 1][x])
			write(2, "Error: 3Invalid map\n", 20);
	if (y - 1 >= 0 && x <= (int)ft_strlen(map[y - 1]))
		if (!map[y - 1][x] || map[y - 1][x] == ' ' || y - 1 < 0)
			write(2, "Error: 4Invalid map\n", 20);
	if (x - 1 < 0 || map[y][x - 1] == ' ')
		write(2, "Error: 5Invalid map\n", 20);
}

void	chek_symbol(char *map)
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
	{
		write(2, "Error: Invalid map\n", 20);
		exit(1);
	}
}

int	*dup_color(char *line)
{
	char	*tmp;
	char	**str;
	int		*arr;

	arr = malloc(3 * sizeof(int));
	tmp = dup_elm(line);
	str = ft_split(tmp, ',');
	if (get_size(str) != 3)
	{
		write(2, " Error: Invalid color\n", 23);
		exit(1);
	}
	arr[0] = color_atoi(str[0]);
	arr[1] = color_atoi(str[1]);
	arr[2] = color_atoi(str[2]);
	return (arr);
}
