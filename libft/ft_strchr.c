/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:36:10 by msainton          #+#    #+#             */
/*   Updated: 2021/06/18 11:18:20 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	c = (unsigned char)c;
	while (s[a])
	{
		if (s[a] == c)
			return ((char *)&s[a]);
		a++;
	}
	if (s[a] == c)
		return ((char *)&s[a]);
	return (NULL);
}
