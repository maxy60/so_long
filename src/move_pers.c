/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:23:22 by user42            #+#    #+#             */
/*   Updated: 2022/02/10 13:26:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pos_perso(t_data *data)
{
	int		i;
	int		j;
	int		n_line;

	j = 0;
	i = 0;
	n_line = data->n_line;
	while (j <= n_line && data->map[j][i] != 'P')
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				break;
			i++;
		}
		if (data->map[j][i] == 'P')
			break;
		j++;
	}
	data->pers_x = i;
	data->pers_y = j;
}

void	move_up(t_data *data)
{
	pos_perso(data);
	data->pers_y -= 1;
	if (data->map[data->pers_y][data->pers_x] == '0')
	{
		data->map[data->pers_y + 1][data->pers_x] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->nbr_pas += 1;
		printf("mouv: %d\n", data->nbr_pas);
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'C')
	{
		data->map[data->pers_y + 1][data->pers_x] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->collectible += 1;
		data->nbr_pas += 1;
		printf("mouv: %d\n", data->nbr_pas);
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'E' && data->collectible == data->nbr_collectible)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

void	move_down(t_data *data)
{
	pos_perso(data);
	data->pers_y += 1;
	if (data->map[data->pers_y][data->pers_x] == '0')
	{
		data->map[data->pers_y - 1][data->pers_x] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->nbr_pas += 1;
		printf("mouv: %d\n", data->nbr_pas);
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'C')
	{
		data->map[data->pers_y - 1][data->pers_x] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->collectible += 1;
		data->nbr_pas += 1;
		printf("mouv: %d\n", data->nbr_pas);
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'E' && data->collectible == data->nbr_collectible)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

void	move_right(t_data *data)
{
	pos_perso(data);
	data->pers_x += 1;
	if (data->map[data->pers_y][data->pers_x] == '0')
	{
		data->map[data->pers_y][data->pers_x - 1] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->nbr_pas += 1;
		printf("mouv: %d\n", data->nbr_pas);
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'C')
	{
		data->map[data->pers_y][data->pers_x - 1] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->collectible += 1;
		data->nbr_pas += 1;
		printf("mouv: %d\n", data->nbr_pas);
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'E' && data->collectible == data->nbr_collectible)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

void	move_left(t_data *data)
{
	pos_perso(data);
	data->pers_x -= 1;
	if (data->map[data->pers_y][data->pers_x] == '0')
	{
		data->map[data->pers_y][data->pers_x + 1] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->nbr_pas += 1;
		printf("mouv: %d\n", data->nbr_pas);
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'C')
	{
		data->map[data->pers_y][data->pers_x + 1] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->collectible += 1;
		data->nbr_pas += 1;
		printf("mouv: %d\n", data->nbr_pas);
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'E' && data->collectible == data->nbr_collectible)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}
