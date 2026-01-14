/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:20:56 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/14 20:39:25 by aqrafi           ###   ########.fr       */
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
		return (free(arr), NULL);
	return (arr);
}

t_elements	*init_elm(void)
{
	t_elements	*elm;

	elm = malloc(sizeof(t_elements));
	elm->c = NULL;
	elm->ea = NULL;
	elm->f = NULL;
	elm->no = NULL;
	elm->so = NULL;
	elm->we = NULL;
	elm->paths = 0;
	return (elm);
}
