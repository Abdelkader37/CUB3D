#include "header.h"

uint32_t	get_texture_pixel(mlx_image_t *texture, uint32_t x, uint32_t y)
{
	int			index;
	uint8_t		*pixels;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;
	
	if (!texture || x >= texture->width || y >= texture->height)
		return (0x808080FF);
	index = (y * texture->width + x) * 4;
	pixels = texture->pixels;
	r = pixels[index];
	g = pixels[index + 1];
	b = pixels[index + 2];
	a = pixels[index + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

void	wall_height(t_mlx_data *data)
{
	data->line_height = (int)(HEIGHT / data->ray_dis);
	data->draw_start = -data->line_height / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_end > HEIGHT)
		data->draw_end = HEIGHT - 1;
}

void wall(t_mlx_data *data, int x)
{
    mlx_image_t *texture;
    int tex_x;
    int y;
    double step;
    double tex_pos;

    if (data->side == 0 && data->ray_x < 0)
        texture = data->west;
    else if (data->side == 0 && data->ray_x > 0)
        texture = data->east;
    else if (data->side == 1 && data->ray_y < 0)
        texture = data->north;
    else
        texture = data->south;
    tex_x = (int)(data->wall_x * texture->width);
    step = 1.0 * texture->height / data->line_height;
    tex_pos = (data->draw_start - HEIGHT / 2 + data->line_height / 2) * step;
    
    y = data->draw_start;
    while (y < data->draw_end)
    {
        int tex_y = (int)tex_pos % texture->height;
        if (tex_y < 0)
            tex_y += texture->height;
        tex_pos += step;
        
        uint32_t color = get_texture_pixel(texture, tex_x, tex_y);
        mlx_put_pixel(data->img, x, y, color);
        y++;
    }
}

void	ceiling(t_mlx_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->draw_start)
	{
		mlx_put_pixel(data->img, x, y, data->ceiling_color);
		y++;
	}
}

void	floor_r(t_mlx_data *data, int x)
{
	int y;

	y = data->draw_end;
	while (y < HEIGHT)
	{
		mlx_put_pixel(data->img, x, y, data->floor_color);
		y++;
	}
}