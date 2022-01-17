/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:36:07 by msainton          #+#    #+#             */
/*   Updated: 2021/06/14 10:41:43 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	dest = (void *)malloc(sizeof(void) * nmemb * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, (nmemb * size));
	return (dest);
}
