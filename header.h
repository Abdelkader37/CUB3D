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
#define MVT_SPEED 0.05
#define MAP_SYMBOLS "NSWE0"
#define PLAYER_SYMBOLS "NSWE"

typedef struct sa_elements
{
    int paths;
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    int    *f;
    int    *c;
    char **map;
}t_elements;

typedef struct sa_mlx_data
{
    mlx_t   *mlx;
    mlx_image_t *north;
    mlx_image_t *south;
    mlx_image_t *west;
    mlx_image_t *east;
    uint32_t color;
    float   dir_x;
    float   dir_y;                                                                                                                                                                          
    int   player_y;
    int   player_x;
    float   camerax;
    float   plan_x;
    float   plan_y;
    float   ray_x;
    float   ray_y;
}t_mlx_data;

char **parse_map(int fd);
void hundle_elem(t_elements *elm, char *line);
t_elements    *init_elm(void);
t_elements *pase_elemetns(int fd);
char	**ft_split(char const *s, char c);
int      word_cont(char *s);
void    skip_space(char **str);
void chek_file_extention(char *s1, char *s2);
int str_char(char c, char *str);
int get_size(char **str);
void chek_player(char **map, int x , int y, int size);
void chek_space(char **map, int x , int y, int size);
void chek_map(char **map);
void    chek_symbol(char *map);
char *dup_elm(char *s);
int color_atoi(char *s);
int *parse_color(char *line);

#endif