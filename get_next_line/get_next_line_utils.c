/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:15:10 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/15 18:08:54 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_cpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		len;
	int		len1;
	int		len2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2 + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (free(s1), s1 = NULL);
	ft_cpy(str, s1, len1);
	ft_cpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_cpy(str, s1, len);
	str[len] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	if (!s)
		return (NULL);
	s1 = (char *)s;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == (char)c)
			return ((char *)&s1[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s1[i]);
	return (NULL);
}
