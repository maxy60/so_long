/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:03:59 by msainton          #+#    #+#             */
/*   Updated: 2021/05/24 14:49:44 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				a;

	d = dest;
	s = src;
	a = 0;
	if (n == 0)
		return (NULL);
	while (a < n)
	{
		d[a] = s[a];
		if (d[a] == (unsigned char)c)
			return ((void *)(dest + a + 1));
		a++;
	}
	return (NULL);
}
