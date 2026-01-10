/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:47:06 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/10 23:53:28 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	int			fd;
	t_elements	*elem;
	t_mlx_data	*data;

	if (ac != 2)
		return (1);
	chek_file_extention(av[1], ".cub");
	fd = open(av[1], O_RDONLY);
	elem = pase_elemetns(fd);
	data = init_data(elem);
	randering(data, elem->map);
	mlx_key_hook(data->mlx, &handle_key_press, data);
	mlx_loop_hook(data->mlx, &loop, data);
	mlx_loop(data->mlx);
}
