#include "header.h"


void get_plan(t_mlx_data *data)
{
    data->plan_x = -(data->dir_y) * 0.66;
    data->plan_y = (data->dir_x) * 0.66;
}

void get_camerax(t_mlx_data *data, int x)
{
    data->camerax = 2 * (float)x / 1500 - 1;
}


void randering(t_mlx_data *data, char **map)
{
    int x;

    get_plan(data)
    x = 0;
    while (x <= 1500)
    {
        get_camerax(data, x);
        data->ray_x = data->dir_x + data->plan_x * data->camerax;
        data->ray_y = data->dir_y + data->plan_y * data->camerax;
        dda(data);
        x++;
    }
    
}


