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

void dda(t_mlx_data *data, char **map)
{
    float   deltax;
    float   deltay;
    int     side;
    int     stepx;
    int     stepy;
    int mapx;
    int mapy;
    int hit;
    float   disx;
    float   disy;
    int map_size;

    mapx = (int)data->player_x;
    mapy = (int)data->player_y;
    map_size = get_size(map);
    if(data->ray_x == 0)
        deltax = 1e13;
    else
        deltax = fabs(1 / data->ray_x);
    if(data->ray_y == 0)
        deltay = 1e13;
    else
        deltay = fabs(1 / data->ray_y);
    hit = 0;
    if(data->ray_x < 0)
    {
        stepx = -1;
        disx = (data->player_x  - mapx) * deltax;
    }
    else
    {
        stepx = 1;
        disx = (mapx + 1  - data->player_x) * deltax;
    }
    if(data->ray_y < 0)
    {
        stepy = -1;
        disy = (data->player_y  - mapy) * deltay;
    }
    else
    {
        stepy = 1;
        disy = (mapy + 1  - data->player_y) * deltay;
    }
    while (!hit)
    {
        if(disx < disy)
        {
            disx += deltax;
            mapx += stepx;
            side = 0;
        }
        else
        {
            disy += deltay;
            mapy += stepy;
            side = 1;
        }
        if(mapx < 0 || mapy < 0  || mapy > map_size || mapx > ft_strlen(map[mapy]))
        {
            hit = 1;
            break;
        }
        if(map[mapy][mapx] == '1')
            hit = 1;
    }
    if(!side)
        data->ray_dis = (mapx - data->player_x + (1 - stepx) / 2) / data->ray_x;
    else
        data->ray_dis = (mapy - data->player_y + (1 - stepy) / 2) / data->ray_y;
}
void randering(t_mlx_data *data, char **map)
{
    int x;

    get_plan(data);
    x = 0;
    while (x <= 1500)
    {
        get_camerax(data, x);
        data->ray_x = data->dir_x + data->plan_x * data->camerax;
        data->ray_y = data->dir_y + data->plan_y * data->camerax;
        dda(data, map);
        x++;
    }
    
}


