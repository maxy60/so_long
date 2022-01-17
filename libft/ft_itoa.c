/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:24:21 by msainton          #+#    #+#             */
/*   Updated: 2021/10/07 19:03:44 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n = n * -1;
		size++;
	}
	if (n == 0)
		size++;
	if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			size++;
		}
	}
	return (size);
}

static char	*alg(char *dest, int n)
{
	int		a;
	long	nb;

	nb = n;
	a = len(nb);
	dest[a] = '\0';
	a = a - 1;
	if (nb == 0)
	{
		dest[0] = 48;
		return (dest);
	}
	if (nb < 0)
	{
		dest[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		dest[a--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		a;
	long	nb;

	nb = n;
	a = len(nb);
	dest = (char *)malloc(sizeof(char) * a + 1);
	if (!dest)
		return (NULL);
	dest = alg(dest, n);
	return (dest);
}
