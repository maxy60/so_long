/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:18:25 by msainton          #+#    #+#             */
/*   Updated: 2021/06/14 11:10:51 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (s2[a] == '\0')
		return ((char *)s1);
	while (s1[a] && a < n)
	{
		b = 0;
		while (s2[b] == s1[a + b] && a + b < n)
		{
			if (s2[b + 1] == '\0')
				return ((char *)&s1[a]);
			b++;
		}
		a++;
	}
	return (NULL);
}
