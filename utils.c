/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:44:53 by aqrafi            #+#    #+#             */
/*   Updated: 2025/10/07 16:45:18 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


t_elements    *init_elm(void)
{
    t_elements *elm;
    elm = malloc(sizeof(t_elements));
    elm->c = NULL;
    elm->ea = NULL;
    elm->f = NULL;
    elm->no = NULL;
    elm->so = NULL;
    elm->we = NULL;
    elm->paths = 0;
    return(elm);
}

void    skip_space(char **str)
{  
    while (*str && **str == ' ')
        (*str)++;
}

int      word_cont(char *s)
{
    int i;
    int cnt;

    cnt = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == ' ')
            i++;
        if(s[i] && s[i] != ' ' && s[i] != '\n')
            cnt++;
        while (s[i] && s[i] != ' ')
            i++;
    }
    return(cnt);
}

int str_char(char c, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(str[i] == c)
            return(1);
        i++;
    }
    return(0);
}
int get_size(char **str)
{
    int y;

    y = 0;
    while (str[y])
        y++;
    return(y);
}

char *dup_elm(char *s)
{
    int i;
    char *rs;
    int len;

    len  = ft_strlen(s);
    rs =  malloc(len);
    i = 0;
    while (s[i] && s[i] != ' ' && s[i] != '\n')
    {
        rs[i] = s[i];
        i++;
    }
    rs[i] = '\0';
    return(rs);
}

int color_atoi(char *s)
{
    int res;
    int i;

    i = 0;
    res = 0;
    if(ft_strlen(s) > 3)
     {
        write(2, "Error: Invalid color\n", 22);
        exit(1);
    }
    while (s[i] && (s[i] >= '0' && s[i] <= '9'))
    {
        res = res * 10 + (s[i] - 48);
        i++;
    }
    if((s[i]&& !(s[i] >= '0' && s[i] <= '9'))|| res > 255  )
    {
        write(2, "Error: Invalid color\n", 22);
        exit(1);
    }
    return(res);
}