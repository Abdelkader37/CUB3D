/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:44:53 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/09 23:07:07 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_elements	*init_elm(void)
{
	t_elements	*elm;

	elm = malloc(sizeof(t_elements));
	elm->c = NULL;
	elm->ea = NULL;
	elm->f = NULL;
	elm->no = NULL;
	elm->so = NULL;
	elm->we = NULL;
	elm->paths = 0;
	return (elm);
}

void	skip_space(char **str)
{
	while (*str && **str == ' ')
		(*str)++;
}

int	word_cont(char *s)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] && s[i] != ' ' && s[i] != '\n')
			cnt++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (cnt);
}

int	str_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
int	get_size(char **str)
{
	int	y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

char	*dup_elm(char *s)
{
	int		i;
	char	*rs;
	int		len;

	len = ft_strlen(s);
	rs = malloc(len);
	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\n')
	{
		rs[i] = s[i];
		i++;
	}
	rs[i] = '\0';
	return (rs);
}

int	color_atoi(char *s)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	if (ft_strlen(s) > 3)
	{
		write(2, "Error: Invalid color\n", 22);
		exit(1);
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	if ((s[i] && !(s[i] >= '0' && s[i] <= '9')) || res > 255)
	{
		write(2, "Error: Invalid color\n", 22);
		exit(1);
	}
	return (res);
}

t_mlx_data	*init_data(t_elements *elm)
{
	t_mlx_data		*data;
	mlx_texture_t	*tmp;

	data = malloc(sizeof(t_mlx_data));
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", 0);
	get_dir(data, elm->map);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->map = elm->map;
	data->ceiling_color = (elm->c[0] << 24) | (elm->c[1] << 16) | (elm->c[2] << 8) | 0xFF;
	data->floor_color = (elm->f[0] << 24) | (elm->f[1] << 16) | (elm->f[2] << 8) | 0xFF;
	tmp = mlx_load_png(elm->no);
	data->north = mlx_texture_to_image(data->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(elm->so);
	data->south = mlx_texture_to_image(data->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(elm->we);
	data->west = mlx_texture_to_image(data->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(elm->ea);
	data->east = mlx_texture_to_image(data->mlx, tmp);
	mlx_delete_texture(tmp);
	return (data);
}

mlx_image_t	*png_to_img(char *path, mlx_t *mlx)
{
	mlx_texture_t	*txt;
	mlx_image_t		*img;

	txt = mlx_load_png(path);
	if (!txt)
	{
		write(2, "Error: invalid path\n", 21);
		exit(1);
	}
	img = mlx_texture_to_image(mlx, txt);
	if (!img)
	{
		write(2, "Error: invalid path\n", 21);
		exit(1);
	}
	return (img);
}
void	get_dir(t_mlx_data *data, char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (str_char(map[y][x], PLAYER_SYMBOLS))
			{
				data->player_x = x + 0.5;
				data->player_y = y + 0.5;
				match_dir(data, map[y][x]);
				return ;
			}
			x++;
		}
		y++;
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
