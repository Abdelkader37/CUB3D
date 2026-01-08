/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseII.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:40:01 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/08 18:21:36 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_color(char **line, t_elements *elm, int *color)
{
	*line = *line + 1;
	skip_space(line);
	color = dup_color(*line);
	elm->paths++;
}

void	parse_texture(char **line, t_elements *elm, char *path)
{
	*line = *line + 1;
	skip_space(line);
	path = dup_elm(*line);
	elm->paths++;
}
void	hundle_elem(t_elements *elm, char *line)
{
	char	*tmp;

	if (word_cont(line) != 2)
	{
		write(2, "Error: Invalid element 1", 25);
		exit(1);
	}
	tmp = line;
	skip_space(&line);
	if (*line == 'F' && *(line + 1) == ' ' && elm->f == NULL)
		parse_color(&line, elm, elm->f);
	else if (*line == 'C' && *(line + 1) == ' ' && elm->c == NULL)
		parse_color(&line, elm, elm->c);
	else if (*line == 'N' && line[1] == 'O' && line[2] == ' ' && elm->no == NULL)
		parse_texture(&line, elm, elm->no);
	else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ' && elm->so == NULL)
		parse_texture(&line, elm, elm->so);
	else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ' && elm->we == NULL)
		parse_texture(&line, elm, elm->we);
	else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ' && elm->ea == NULL)
		parse_texture(&line, elm, elm->ea);
	else
	{
		write(2, "Error: Invalid element", 25);
		exit(1);
	}
	line = tmp;
}
