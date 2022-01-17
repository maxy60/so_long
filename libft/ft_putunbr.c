/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:08:39 by msainton          #+#    #+#             */
/*   Updated: 2021/10/21 14:38:50 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr(unsigned int n)
{
	if ((int)n >= 0 && n < 10)
		ft_putchar(n + 48);
	else if ((int)n < 0)
	{
		ft_putchar('-');
		ft_putunbr(n * (-1));
	}
	else
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
}
