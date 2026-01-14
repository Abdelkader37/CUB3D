/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:39:42 by rroundi           #+#    #+#             */
/*   Updated: 2026/01/15 00:43:16 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "MLX42/include/MLX42/MLX42.h"

#define ROT_SPEED 0.05
#define WIDTH   1200
#define HEIGHT  1000
#define MVT_SPEED 0.15
#define MAP_SYMBOLS "NSWE0"
#define PLAYER_SYMBOLS "NSWE"
#define SPEED 0.18
#define MLX_KEY_W 87
#define MLX_KEY_S 83
#define MLX_KEY_D 68
#define MLX_KEY_A 65
#define ROT 0.15f
#define L_KEY 37
#define R_KEY 39

typedef struct sa_elements
{
    int paths;
    char	*no;
    char	*so;
    char	*we;
    char    *ea;
    int    *f;
    int    *c;
    char **map;
    int fd;
}t_elements;

typedef struct s_ray
{
    float   deltax;
    float   deltay;
    float   disx;
    float   disy;
    int     stepx;
    int     stepy;
    int     mapx;
    int     mapy;
    int     side;
}   t_ray;
typedef struct sa_mlx_data
{
    mlx_t   *mlx;
	mlx_image_t *img;
    mlx_image_t *north;
    mlx_image_t *south;
    mlx_image_t *west;
    mlx_image_t *east;
    uint32_t color;
    float   dir_x;
    float   dir_y;                                                                                                                                                                       
    float   player_y;
    float   player_x;
    float   camerax;
    float   plan_x;
    float   plan_y;
    float   ray_x;
    float   ray_y;
    float   ray_dis;
	int		line_height;
	int		draw_start;
	int		draw_end;
	char	**map;
	t_elements *elements;
	int side;
	double wall_x;

	uint32_t floor_color;
    uint32_t ceiling_color;
}t_mlx_data;

t_mlx_data *init_data(t_elements *elm);
void parse_map(int fd, t_elements *elm);
void	init_delta(t_mlx_data *data, t_ray *ray);
void	get_camerax(t_mlx_data *data, int x);
void	get_plan(t_mlx_data *data);
void	init_steps(t_mlx_data *data, t_ray *ray);
void hundle_elem(t_elements *elm, char *line);
t_elements    *init_elm(void);
t_elements *pase_elemetns(int fd);
char	**ft_split(char const *s, char c);
int      word_cont(char *s);
void    skip_space(char **str);
void chek_file_extention(char *s1, char *s2);
int str_char(char c, char *str);
int get_size(char **str);
void	chek_player(t_elements *elm, int x, int y, int size);
void	chek_space(t_elements *elm, int x, int y, int size);
void	chek_map(t_elements *elm);
void    chek_symbol(char *map, t_elements *elm);
char *dup_elm(char *s);
int color_atoi(char *s);
int		*dup_color(char *line);
void	wall_height(t_mlx_data	*data);
void    get_dir(t_mlx_data  *data, char **map);
mlx_image_t	*png_to_img(char *path, t_mlx_data *data);
void 	randering(t_mlx_data *data, char **map);
void     match_dir(t_mlx_data   *data, char c);
void	ceiling(t_mlx_data *data, int x);
void	wall(t_mlx_data *data, int x);
void	floor_r(t_mlx_data *data, int x);
void	forward(t_mlx_data *data);
void	back(t_mlx_data *data);
void	left(t_mlx_data *data);
void	right(t_mlx_data *data);
void	handle_key_press(mlx_key_data_t key, void	*par);
void	loop(void *par);
void	rotate_r(t_mlx_data *data);
void	rotate_l(t_mlx_data *data);
void ft_error(char *error, t_elements *elm, char *line);
void	free_elm(t_elements *elm, char *line);
void	free_map(char **map);
// void	free_eml2(t_elements *elm);
void	free_data(t_mlx_data *data);
void	free_map(char **map);

#endif