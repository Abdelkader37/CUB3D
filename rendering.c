
#include "header.h"

void    wall_height(t_mlx_data    *data)
{
    data->line_height = (int)(1500 / data->ray_dis);
    data->draw_start = -data->line_height / 2 + 1500 / 2;
    if (data->draw_start < 0)
        data->draw_start = 0;
    data->draw_end = data->line_height / 2 + 1500 / 2;
    if (data->draw_end > 1500)
        data->draw_end = 1499;
}

void    ceiling(t_mlx_data *data, int x)
{
    int y;

    y = 0;
    while (y < data->draw_start)
    {
        mlx_put_pixel(data->img, x, y, 0x87CEEBFF);
        y++;
    }
}
void    wall(t_mlx_data *data, int x)
{
    int y;

    y = data->draw_start;
    while (y < data->draw_end)
    {
        mlx_put_pixel(data->img, x, y, 0x808080FF);
        y++;
    }
}
void    floor(t_mlx_data *data, int x)
{
    int y;

    y = data->draw_end;
    while (y < 1500)
    {
        mlx_put_pixel(data->img, x, y, 0x228B22FF);
        y++;
    }
}
