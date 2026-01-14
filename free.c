#include "header.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_data(t_mlx_data *data)
{
	if (!data)
		return ;
	mlx_delete_image(data->mlx,data->south);
	mlx_delete_image(data->mlx,data->west);
	mlx_delete_image(data->mlx, data->north);
	mlx_delete_image(data->mlx, data->east);
	free_map(data->map);
	free_elm(data->elements,NULL);
	free(data);
}