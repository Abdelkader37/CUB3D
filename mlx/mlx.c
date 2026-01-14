/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:33:31 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/14 20:43:05 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_mlx_data	*init_data(t_elements *elm)
{
	t_mlx_data	*data;

	data = malloc(sizeof(t_mlx_data));
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", 0);
	get_dir(data, elm->map);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	data->elements = elm;
	data->map = elm->map;
	data->ceiling_color = (elm->c[0] << 24) 
		| (elm->c[1] << 16) | (elm->c[2] << 8) | 0xFF;
	data->floor_color = (elm->f[0] << 24) 
		| (elm->f[1] << 16) | (elm->f[2] << 8) | 0xFF;
	data->north = png_to_img(elm->no, data);
	data->south = png_to_img(elm->so, data);
	data->west = png_to_img(elm->we, data);
	data->east = png_to_img(elm->ea, data);
	return (data);
}

mlx_image_t	*png_to_img(char *path, t_mlx_data *data)
{
	mlx_texture_t	*txt;
	mlx_image_t		*img;

	txt = mlx_load_png(path);
	if (!txt)
	{
		free_data(data);
		ft_error("Error: invalid path", NULL, NULL);
	}
	img = mlx_texture_to_image(data->mlx, txt);
	if (!img)
	{
		free_data(data);
		ft_error("Error: invalid path", NULL, NULL);
	}
	mlx_delete_texture(txt);
	return (img);
}
