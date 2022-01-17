/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:05:10 by msainton          #+#    #+#             */
/*   Updated: 2021/06/18 13:27:14 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	len_dst;
	size_t	res;
	size_t	len_src;
	size_t	a;

	s = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(s);
	res = 0;
	a = 0;
	if (size > len_dst)
		res = len_src + len_dst;
	else
		res = len_src + size;
	while (s[a] && (len_dst + 1) < size)
	{
		dst[len_dst] = s[a];
		len_dst++;
		a++;
	}
	dst[len_dst] = '\0';
	return (res);
}
