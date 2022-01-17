/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:17:54 by msainton          #+#    #+#             */
/*   Updated: 2021/06/18 17:17:57 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	b;

	b = 0;
	if (!dest || !src)
		return (0);
	while (src[b] != '\0')
		b++;
	if (size == 0)
		return (b);
	a = 0;
	while (a < b && a < size - 1)
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (b);
}
