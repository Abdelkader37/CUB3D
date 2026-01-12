/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroundi <rroundi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:42:21 by rroundi           #+#    #+#             */
/*   Updated: 2026/01/11 10:52:31 by rroundi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_l(t_mlx_data *data)
{
	float	odir_x;
	float	oplan_x;

	odir_x = data->dir_x;
	oplan_x = data->plan_x;
	data->dir_x = data->dir_x * cos(ROT) - data->dir_y * sin(ROT);
	data->dir_y = odir_x * sin(ROT) + data->dir_y * cos(ROT);
	data->plan_x = data->plan_x * cos(ROT) - data->plan_y * sin(ROT);
	data->plan_y = oplan_x * sin(ROT) + data->plan_y * cos(ROT);
}

void	rotate_r(t_mlx_data *data)
{
	float odir_x;
	float oplan_x;

	odir_x = data->dir_x;
	oplan_x = data->plan_x;
	data->dir_x = data->dir_x * cos(-ROT) - data->dir_y * sin(-ROT);
	data->dir_y = odir_x * sin(-ROT) + data->dir_y * cos(-ROT);
	data->plan_x = data->plan_x * cos(-ROT) - data->plan_y * sin(-ROT);
	data->plan_y = oplan_x * sin(-ROT) + data->plan_y * cos(-ROT);
}