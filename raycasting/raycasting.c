/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:56:08 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/14 20:37:03 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	dda_loop(t_ray *ray, char **map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->disx < ray->disy)
		{
			ray->disx += ray->deltax;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->disy += ray->deltay;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (map[ray->mapy][ray->mapx] == '1')
			hit = 1;
	}
}

static void	wall_dist(t_mlx_data *data, t_ray *ray)
{
	if (ray->side == 0)
		data->ray_dis = (ray->disx - ray->deltax);
	else
		data->ray_dis = (ray->disy - ray->deltay);
	if (ray->side == 0)
		data->ray_dis = (ray->mapx - data->player_x + (1 - ray->stepx) / 2)
			/ data->ray_x;
	else
		data->ray_dis = (ray->mapy - data->player_y + (1 - ray->stepy) / 2)
			/ data->ray_y;
	data->side = ray->side;
	if (ray->side == 0)
		data->wall_x = data->player_y + data->ray_dis * data->ray_y;
	else
		data->wall_x = data->player_x + data->ray_dis * data->ray_x;
	data->wall_x -= floor((data->wall_x));
}

void	dda(t_mlx_data *data, char **map)
{
	t_ray	ray;

	init_delta(data, &ray);
	init_steps(data, &ray);
	dda_loop(&ray, map);
	wall_dist(data, &ray);
}

void	randering(t_mlx_data *data, char **map)
{
	int	x;

	get_plan(data);
	x = 0;
	while (x <= WIDTH)
	{
		get_camerax(data, x);
		data->ray_x = data->dir_x + data->plan_x * data->camerax;
		data->ray_y = data->dir_y + data->plan_y * data->camerax;
		dda(data, map);
		wall_height(data);
		ceiling(data, x);
		wall(data, x);
		floor_r(data, x);
		x++;
	}
}

void	match_dir(t_mlx_data *data, char c)
{
	if (c == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
	}
	else if (c == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
	}
	else if (c == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	else if (c == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
}
