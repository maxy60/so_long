/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:43:49 by msainton          #+#    #+#             */
/*   Updated: 2021/11/04 16:58:02 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *str)
{
	int			a;
	int			sign;
	long int	nbr;

	a = 0;
	sign = 1;
	nbr = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == ' ')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			sign = sign * -1;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		nbr = nbr * 10 + str[a] - 48;
		a++;
	}
	nbr = nbr * sign;
	return (nbr);
}
