/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:12:13 by msainton          #+#    #+#             */
/*   Updated: 2021/06/18 11:19:07 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = 0;
	c = (unsigned char)c;
	while (s[a])
		a++;
	if (s[a] == c)
		return ((char *)&s[a]);
	while (a >= 0)
	{
		if (s[a] == c)
			return ((char *)&s[a]);
		a--;
	}
	return (NULL);
}
