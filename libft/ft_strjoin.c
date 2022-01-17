/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:28:45 by msainton          #+#    #+#             */
/*   Updated: 2021/12/20 12:36:14 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
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
	return (dest);
}
