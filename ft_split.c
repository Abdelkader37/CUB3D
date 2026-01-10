/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:15:28 by aqrafi            #+#    #+#             */
/*   Updated: 2026/01/10 23:53:12 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			cont++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cont);
}

static char	**freeall(char **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**alloc_s(const char *s, char c, int cnt)
{
	char	**str;
	int		len;
	int		j;

	j = 0;
	str = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!str)
		return (NULL);
	while (j < cnt)
	{
		len = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		str[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!str[j])
			return (freeall(str, j));
		j++;
	}
	str[cnt] = NULL;
	return (str);
}

static char	**copy_s(char **str, const char *s, char c, int cnt)
{
	int	j;
	int	f;

	j = 0;
	while (j < cnt)
	{
		f = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			str[j][f++] = *s;
			s++;
		}
		str[j][f] = '\0';
		j++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		cnt;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	cnt = count_word(s, c);
	str = alloc_s(s, c, cnt);
	if (!str)
		return (NULL);
	str = copy_s(str, s, c, cnt);
	return (str);
}
