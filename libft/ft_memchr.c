/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:26:36 by msainton          #+#    #+#             */
/*   Updated: 2021/06/14 10:57:04 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			a;

	a = 0;
	tmp = (unsigned char *)s;
	while (a < n)
	{
		while (*tmp == ((unsigned char)c))
			return (tmp);
		tmp++;
		a++;
	}
	return (NULL);
}
