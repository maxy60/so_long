/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:50:19 by msainton          #+#    #+#             */
/*   Updated: 2021/06/21 14:49:44 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	a;

	a = 0;
	if (n == 0)
		return (0);
	while (s1[a] && s2[a] && s1[a] == s2[a] && (size_t)a < n - 1)
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
