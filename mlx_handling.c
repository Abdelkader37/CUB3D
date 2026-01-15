/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:34:35 by rroundi           #+#    #+#             */
/*   Updated: 2026/01/15 18:04:30 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_key_press(mlx_key_data_t key, void *par)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)par;
	if (key.action == MLX_PRESS || key.action == MLX_REPEAT)
	{
		if (key.key == MLX_KEY_W)
			forward(data);
		if (key.key == MLX_KEY_S)
			back(data);
		if (key.key == MLX_KEY_A)
			left(data);
		if (key.key == MLX_KEY_D)
			right(data);
		if (key.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		if (key.key == MLX_KEY_LEFT)
			rotate_r(data);
		if (key.key == MLX_KEY_RIGHT)
			rotate_l(data);
	}
}

void	loop(void *par)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)par;
	randering(data, data->map);
}
