/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:09:12 by msainton          #+#    #+#             */
/*   Updated: 2021/12/20 13:55:39 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	a;

	a = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[a])
	{
		dest[a] = s[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
