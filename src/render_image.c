/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:56:03 by msainton          #+#    #+#             */
/*   Updated: 2022/02/10 19:23:16 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_cross(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (keysym == 119)
		move_up(data);
	if (keysym == 97)
		move_left(data);
	if (keysym == 115)
		move_down(data);
	if (keysym == 100)
		move_right(data);
	return (0);
}

void	put_img(t_data *data, int w, int h, char *textures)
{
	data->image.img
		= mlx_xpm_file_to_image
		(data->mlx_ptr, textures, &data->image.width, &data->image.height);
	mlx_put_image_to_window
		(data->mlx_ptr, data->win_ptr, data->image.img, w, h);
	mlx_destroy_image(data->mlx_ptr, data->image.img);
}

void	do_map(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->n_line)
	{
		i = 0;
		while (i < data->size_l)
		{
			do_map2(i, j, data);
			i++;
		}
		j++;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 60, 0xff0000, "Moves :");
	data->nbr_pas_aff = ft_itoa(data->nbr_pas);
	mlx_string_put
		(data->mlx_ptr, data->win_ptr, 75, 60, 0xff0000, data->nbr_pas_aff);
	free(data->nbr_pas_aff);
}

int	try(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr
		= mlx_new_window(data->mlx_ptr, data->x, data->y, "VIDEO GAME");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	do_map(data);
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, &handle_cross, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_loop(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_map(data->map);
	free(data->mlx_ptr);
	exit(0);
}
