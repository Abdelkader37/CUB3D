/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:40:01 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/10 00:02:25 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_color(char **line, t_elements *elm, int **color)
{
	*line = *line + 1;
	skip_space(line);
	*color = dup_color(*line);
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
		parse_color(&line, elm, &elm->f);
	else if (*line == 'C' && *(line + 1) == ' ' && elm->c == NULL)
		parse_color(&line, elm, &elm->c);
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
void	free_elm(t_elements *elm, char *line)
{
	free(elm->ea);
	free(elm->no);
	free(elm->so);
	free(elm->we);
	free(line);
}

void	ft_error(char *error, t_elements *elm, char *line)
{
	printf("%s\n", error);
	free_elm(elm, line);
	exit(1);
}
