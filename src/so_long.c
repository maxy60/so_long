/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:08:08 by msainton          #+#    #+#             */
/*   Updated: 2022/02/10 19:46:38 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_data(t_data *data, char **av)
{
	data->x = size_line(av) * SIZE_IMG;
	data->y = nbr_line(av) * SIZE_IMG;
	data->size_l = size_line(av);
	data->n_line = nbr_line(av);
	data->pers_x = 0;
	data->pers_y = 0;
	data->collectible = 0;
	data->nbr_collectible = collectible(data);
	data->nbr_pas = 0;
}

void	init_img(t_img *test)
{
	test->img = NULL;
	test->width = 0;
	test->height = 0;
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	main(int ac, char **av)
{
	t_img	test;
	t_data	data;

	if (ac == 2 && check_file(av[1]) == 0
		&& files_name(av[1]) == 0 && if_is_file(av[1]) == 0)
	{
		data.map = parse(av);
		init_data(&data, av);
		if (data.map == NULL || check_size_line(data.map, av) == 1
			|| wall(&data) == 1 || check_map(&data) == 1
			|| check_element(&data) == 1)
		{
			ft_putstr_fd("Error: the map has incorrect characters/format\n", 2);
			free_map(data.map);
			return (0);
		}
		init_img(&test);
		try(&data);
	}
	else
		ft_putstr_fd("Error: usage: ./so_long <map.ber>\n", 2);
	return (0);
}
