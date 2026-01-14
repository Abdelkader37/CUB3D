/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:40:01 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/14 20:39:58 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_color(char **line, t_elements *elm, int **color, char *tmp)
{
	*line = *line + 1;
	skip_space(line);
	*color = dup_color(*line);
	if (*color == NULL)
		ft_error("Error: Invalid color", elm, tmp);
	elm->paths++;
}

char	*parse_texture(char **line, t_elements *elm)
{
	*line = *line + 2;
	skip_space(line);
	elm->paths++;
	return (dup_elm(*line));
}

void	hundle_elem(t_elements *elm, char *line)
{
	char	*tmp;

	if (word_cont(line) != 2)
		ft_error("Error: Invalid element 1", elm, line);
	tmp = line;
	skip_space(&line);
	if (*line == 'F' && *(line + 1) == ' ' && elm->f == NULL)
		parse_color(&line, elm, &elm->f, tmp);
	else if (*line == 'C' && *(line + 1) == ' ' && elm->c == NULL)
		parse_color(&line, elm, &elm->c, tmp);
	else if (*line == 'N' && line[1] == 'O' && line[2] == ' '
		&& elm->no == NULL)
		elm->no = parse_texture(&line, elm);
	else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' '
		&& elm->so == NULL)
		elm->so = parse_texture(&line, elm);
	else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' '
		&& elm->we == NULL)
		elm->we = parse_texture(&line, elm);
	else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' '
		&& elm->ea == NULL)
		elm->ea = parse_texture(&line, elm);
	else
		ft_error("Error: Invalid element", elm, tmp);
	line = tmp;
}

char	*dup_elm(char *s)
{
	int		i;
	char	*rs;
	int		len;

	len = ft_strlen(s);
	rs = malloc(len);
	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\n')
	{
		rs[i] = s[i];
		i++;
	}
	rs[i] = '\0';
	return (rs);
}

int	color_atoi(char *s)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	if (ft_strlen(s) > 3)
		return (-1);
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	if ((s[i] && !(s[i] >= '0' && s[i] <= '9')) || res > 255)
		return (-1);
	return (res);
}
