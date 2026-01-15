/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:59:44 by rroundi           #+#    #+#             */
/*   Updated: 2026/01/15 21:38:59 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

uint32_t	get_texture_pixel(mlx_image_t *texture, uint32_t x, uint32_t y)
{
	int		index;
	uint8_t	*pixels;

	if (!texture || x >= texture->width || y >= texture->height)
		return (0x808080FF);
	index = (y * texture->width + x) * 4;
	pixels = texture->pixels;
	return ((uint32_t)pixels[index] << 24 
		| (uint32_t)pixels[index + 1] << 16 
		| (uint32_t)pixels[index + 2] << 8 | (uint32_t)pixels[index + 3]);
}

void	wall_height(t_mlx_data *data)
{
	data->line_height = (int)(HEIGHT / data->ray_dis);
	data->draw_start = -data->line_height / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_end > HEIGHT)
		data->draw_end = HEIGHT - 1;
}

mlx_image_t	*get_texture(t_mlx_data *data)
{
	if (data->side == 0 && data->ray_x < 0)
		return (data->west);
	else if (data->side == 0 && data->ray_x > 0)
		return (data->east);
	else if (data->side == 1 && data->ray_y < 0)
		return (data->north);
	else
		return (data->south);
}
