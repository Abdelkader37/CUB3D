/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:28:14 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/15 00:03:36 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_data(t_mlx_data *data)
{
	if (!data)
		return ;
	mlx_delete_image(data->mlx, data->south);
	mlx_delete_image(data->mlx, data->west);
	mlx_delete_image(data->mlx, data->north);
	mlx_delete_image(data->mlx, data->east);
	free_map(data->map);
	free_elm(data->elements, NULL);
	free(data);
}

void	free_elm(t_elements *elm, char *line)
{
	free(elm->ea);
	free(elm->no);
	free(elm->so);
	free(elm->we);
	free(elm->c);
	free(elm->f);
	close(elm->fd);
	free(line);
	free(elm);
}

void	ft_error(char *error, t_elements *elm, char *line)
{
	printf("%s\n", error);
	if (elm)
	{
		free_map(elm->map);
		free_elm(elm, line);
	}
	exit(1);
}
