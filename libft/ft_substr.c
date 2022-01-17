/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:02:04 by msainton          #+#    #+#             */
/*   Updated: 2021/06/21 15:23:46 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	a;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	a = ft_strlen(s + start);
	if (a < len)
		len = a;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}
