/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:18:13 by rroundi           #+#    #+#             */
/*   Updated: 2026/01/15 00:05:20 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	forward(t_mlx_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_x + data->dir_x * SPEED;
	new_y = data->player_y + data->dir_y * SPEED;
	if (data->map[(int)new_y][(int)new_x] != '1')
	{
		data->player_x = new_x;
		data->player_y = new_y;
	}
}

void	back(t_mlx_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_x - data->dir_x * SPEED;
	new_y = data->player_y - data->dir_y * SPEED;
	if (data->map[(int)new_y][(int)new_x] != '1')
	{
		data->player_x = new_x;
		data->player_y = new_y;
	}
}

void	left(t_mlx_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_x - data->plan_x * SPEED;
	new_y = data->player_y - data->plan_y * SPEED;
	if (data->map[(int)new_y][(int)new_x] != '1')
	{
		data->player_x = new_x;
		data->player_y = new_y;
	}
}

void	right(t_mlx_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_x + data->plan_x * SPEED;
	new_y = data->player_y + data->plan_y * SPEED;
	if (data->map[(int)new_y][(int)new_x] != '1')
	{
		data->player_x = new_x;
		data->player_y = new_y;
	}
}
