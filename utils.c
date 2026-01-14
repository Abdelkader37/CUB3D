/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:44:53 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/14 20:44:14 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	skip_space(char **str)
{
	while (*str && **str == ' ')
		(*str)++;
}

int	word_cont(char *s)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] && s[i] != ' ' && s[i] != '\n')
			cnt++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (cnt);
}

int	str_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_size(char **str)
{
	int	y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

void	get_dir(t_mlx_data *data, char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (str_char(map[y][x], PLAYER_SYMBOLS))
			{
				data->player_x = x + 0.5;
				data->player_y = y + 0.5;
				match_dir(data, map[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
}
