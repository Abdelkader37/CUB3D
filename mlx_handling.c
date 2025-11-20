/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:34:35 by rroundi           #+#    #+#             */
/*   Updated: 2025/11/19 13:04:27 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_key_press(mlx_key_data_t key, void	*par)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)par;
	if (key.action == MLX_PRESS || key.action == MLX_REPEAT)
	{
		if (key.key == MLX_KEY_W)
        	forward(data);
        else if (key.key == MLX_KEY_S)
            back(data);
        else if (key.key == MLX_KEY_A)
            left(data);
        else if (key.key == MLX_KEY_D)
            right(data);
		else if (key.key == MLX_KEY_ESCAPE)
            mlx_close_window(data->mlx);
	}
}
void	loop(void *par)
{
	t_mlx_data *data;

	data = (t_mlx_data *)par;
	randering(data, data->map);
}