/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:11:09 by aqrafi            #+#    #+#             */
/*   Updated: 2024/12/02 22:16:12 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
void	*ft_cpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*get_all(int fd, char *line);
char	*get_lin(char *str);
char	*get_remain(char *str);

#endif