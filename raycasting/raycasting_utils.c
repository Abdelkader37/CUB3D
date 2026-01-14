/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:35:36 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/14 20:38:02 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_plan(t_mlx_data *data)
{
	data->plan_x = -(data->dir_y) * 0.66;
	data->plan_y = (data->dir_x) * 0.66;
}

void	get_camerax(t_mlx_data *data, int x)
{
	data->camerax = 2 * (float)x / WIDTH - 1;
}

void	init_delta(t_mlx_data *data, t_ray *ray)
{
	if (data->ray_x == 0)
		ray->deltax = 1e13;
	else
		ray->deltax = fabs(1 / data->ray_x);
	if (data->ray_y == 0)
		ray->deltay = 1e13;
	else
		ray->deltay = fabs(1 / data->ray_y);
}

void	init_steps(t_mlx_data *data, t_ray *ray)
{
	ray->mapx = (int)data->player_x;
	ray->mapy = (int)data->player_y;
	if (data->ray_x < 0)
	{
		ray->stepx = -1;
		ray->disx = (data->player_x - ray->mapx) * ray->deltax;
	}
	else
	{
		ray->stepx = 1;
		ray->disx = (ray->mapx + 1 - data->player_x) * ray->deltax;
	}
	if (data->ray_y < 0)
	{
		ray->stepy = -1;
		ray->disy = (data->player_y - ray->mapy) * ray->deltay;
	}
	else
	{
		ray->stepy = 1;
		ray->disy = (ray->mapy + 1 - data->player_y) * ray->deltay;
	}
}
