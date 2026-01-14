/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:51:52 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/15 00:53:10 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

uint32_t	get_texture_pixel(mlx_image_t *texture, uint32_t x, uint32_t y)
{
	int			index;
	uint8_t		*pixels;

	if (!texture || x >= texture->width || y >= texture->height)
		return (0x808080FF);
	index = (y * texture->width + x) * 4;
	pixels = texture->pixels;
	return ((uint32_t)pixels[index] << 24 
		| (uint32_t)pixels[index + 1] << 16 | (uint32_t)pixels[index + 2] << 8 
		| (uint32_t)pixels[index + 3]);
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

void	wall(t_mlx_data *data, int x)
{
	mlx_image_t	*texture;
	int			tex_x;
	int			y;
	double		step;
	double		tex_pos;
	int			tex_y;
	uint32_t	color;

	if (data->side == 0 && data->ray_x < 0)
		texture = data->west;
	else if (data->side == 0 && data->ray_x > 0)
		texture = data->east;
	else if (data->side == 1 && data->ray_y < 0)
		texture = data->north;
	else
		texture = data->south;
	tex_x = (int)(data->wall_x * texture->width);
	step = 1.0 * texture->height / data->line_height;
	tex_pos = (data->draw_start - HEIGHT / 2 + data->line_height / 2) * step;
	y = data->draw_start;
	while (y < data->draw_end)
	{
		tex_y = (int)tex_pos % texture->height;
		if (tex_y < 0)
			tex_y += texture->height;
		tex_pos += step;
		color = get_texture_pixel(texture, tex_x, tex_y);
		mlx_put_pixel(data->img, x, y, color);
		y++;
	}
}

void	ceiling(t_mlx_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->draw_start)
	{
		mlx_put_pixel(data->img, x, y, data->ceiling_color);
		y++;
	}
}

void	floor_r(t_mlx_data *data, int x)
{
	int	y;

	y = data->draw_end;
	while (y < HEIGHT)
	{
		mlx_put_pixel(data->img, x, y, data->floor_color);
		y++;
	}
}
