/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:47:06 by aqrafi            #+#    #+#             */
/*   Updated: 2025/10/13 14:23:02 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	mlx_t *mlx;
	int			fd;
	t_elements	*elem;

	if (ac != 2)
		return (1);
	chek_file_extention(av[1], ".cub");
	fd = open(av[1], O_RDONLY);
	elem = pase_elemetns(fd);
	// mlx = mlx_init(1500,1500, "CUB3D", 0);
	// mlx_texture_t *imgg = mlx_load_png("square-.png");
	// if (imgg == NULL)
	// {
	// 	printf("l7waaa\n");
	// 	exit(-1);
	// }
	// mlx_image_t *img1  = mlx_texture_to_image(mlx, imgg);
	// mlx_image_to_window(mlx, img1, 500, 500);
	// mlx_image_t *img = mlx_new_image(mlx, 1000, 1000);
	// int x = 0;
	// int y;
	// while (x < 1000)
	// {
	// 	y  = 0;
	// 	while (y < 500)
	// 	{
	// 		mlx_put_pixel(img, y, x, 0xff0000ff);
	// 		printf("herer\n");
	// 		y+=1;
	// 	}
	// 	x+=1;
	// }
	// mlx_image_to_window(mlx, img, 0, 0);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
}
