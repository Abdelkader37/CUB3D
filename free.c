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

void	free_eml2(t_elements *elm)
{
	if (!elm)
		return ;
	if (elm->so)
		free(elm->so);
	if (elm->ea)
		free(elm->ea);
	if (elm->no)
		free(elm->no);
	if (elm->we)
		free(elm->we);
	if (elm->c)
		free(elm->c);
	if (elm->f)
		free(elm->f);
	if (elm->map)
		free_map(elm->map);
	free(elm);
}

void	free_data(t_mlx_data *data)
{
	if (!data)
		return ;
	free(data);
}