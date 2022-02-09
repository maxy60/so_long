/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:59:12 by msainton          #+#    #+#             */
/*   Updated: 2022/02/09 14:34:21 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!dest)
		return (NULL);
	while (s1[a])
	{
		dest[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		dest[a + b] = s2[b];
		b++;
	}
	dest[a + b] = '\0';
	free((char *)s1);
	return (dest);
}

char	*stock_line(char *dest)
{
	size_t	a;
	char	*str;

	a = 0;
	while (dest[a] != '\n' && dest[a] != '\0')
		a++;
	str = (char *)malloc(sizeof(char) * (a + 2));
	if (!str)
		return (NULL);
	a = 0;
	while (dest[a] != '\n' && dest[a] != '\0')
	{
		str[a] = dest[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

char	*stock_rest(char *dest)
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	while (dest[a] != '\n' && dest[a] != '\0')
		a++;
	if (dest[a] == 0 || dest[a + 1] == 0)
	{
		free(dest);
		return (NULL);
	}
	a++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(dest + a) + 1));
	if (!str)
		return (NULL);
	b = 0;
	while (dest[a])
		str[b++] = dest[a++];
	str[b] = 0;
	free(dest);
	dest = NULL;
	return (str);
}
