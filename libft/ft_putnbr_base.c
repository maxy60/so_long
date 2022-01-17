/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:51:51 by msainton          #+#    #+#             */
/*   Updated: 2021/10/22 12:07:01 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	erreur(char *base)
{
	int	a;
	int	b;

	a = 0;
	while (base[a] != '\0')
	{
		b = a + 1;
		while (base[b] != '\0')
		{
			if (base[a] == base[b] || base[a] == '-' || base[a] == '+'
				|| base[b] == '-' || base[b] == '+')
				return (1);
			b++;
		}
		a++;
	}
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (1);
	return (0);
}

void	ft_base(unsigned int nbr, char *base, unsigned int size)
{
	if (nbr >= size)
		ft_base(nbr / size, base, size);
	ft_putchar(base[nbr % size]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	a;

	a = ft_strlen(base);
	if (erreur(base) == 1)
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	ft_base(nbr, base, a);
}
