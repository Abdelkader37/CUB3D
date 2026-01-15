/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:51:52 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/15 18:00:18 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_wall(t_mlx_data *data, mlx_image_t *texture, int x, int tex_x)
{
	double		step;
	double		tex_pos;
	int			tex_y;
	uint32_t	color;
	int			y;

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

void	wall(t_mlx_data *data, int x)
{
	mlx_image_t	*texture;
	int			tex_x;

	texture = get_texture(data);
	tex_x = (int)(data->wall_x * texture->width);
	draw_wall(data, texture, x, tex_x);
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
