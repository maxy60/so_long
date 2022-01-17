/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:12:51 by msainton          #+#    #+#             */
/*   Updated: 2021/06/21 15:34:01 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charset(const char *set, char s1)
{
	size_t	a;

	a = 0;
	while (set[a])
	{
		if (set[a] == s1)
			return (1);
		a++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*dest;
	size_t	a;
	size_t	b;
	size_t	c;

	if (!s1 || !set)
		return (NULL);
	a = 0;
	b = ft_strlen(s1);
	while (charset(set, s1[a]) == 1)
		a++;
	while (b > a && charset(set, s1[b - 1]) == 1)
		b--;
	dest = (char *)malloc(sizeof(char) * (b - a) + 1);
	if (!dest)
		return (NULL);
	c = 0;
	while (a < b)
		dest[c++] = s1[a++];
	dest[c] = '\0';
	return (dest);
}
