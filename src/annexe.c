/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:16:16 by msainton          #+#    #+#             */
/*   Updated: 2022/02/10 19:22:15 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map2(t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (i < data->n_line - 1)
	{
		j = 0;
		while (data->map[i][j])
		{
			str = data->map[i];
			if (str[j] != '0' && str[j] != '1'
				&& str[j] != 'P' && str[j] != 'C' && str[j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	do_map2(int i, int j, t_data *data)
{
	int	h;
	int	w;

	h = 64 * j;
	w = 64 * i;
	if (data->map[j][i] == '0')
		put_img(data, w, h, "./textures/floor.XPM");
	else if (data->map[j][i] == '1')
		put_img(data, w, h, "./textures/trap.XPM");
	else if (data->map[j][i] == 'P')
		put_img(data, w, h, "./textures/perso_face.XPM");
	else if (data->map[j][i] == 'C')
		put_img(data, w, h, "./textures/item.XPM");
	else if (data->map[j][i] == 'E')
		put_img(data, w, h, "./textures/exit.XPM");
}
