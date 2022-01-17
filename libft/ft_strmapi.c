/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:22:15 by msainton          #+#    #+#             */
/*   Updated: 2021/06/18 16:05:22 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = (f)(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
