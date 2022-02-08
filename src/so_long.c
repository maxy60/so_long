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

int	handle_cross(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
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
	data->nbr_pas += 1;
	printf("mouv: %d\n", data->nbr_pas);
	return (0);
}



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
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'C')
	{
		data->map[data->pers_y + 1][data->pers_x] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->collectible += 1;
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
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'C')
	{
		data->map[data->pers_y - 1][data->pers_x] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->collectible += 1;
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
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'C')
	{
		data->map[data->pers_y][data->pers_x - 1] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->collectible += 1;
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
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'C')
	{
		data->map[data->pers_y][data->pers_x + 1] = '0';
		data->map[data->pers_y][data->pers_x] = 'P';
		data->collectible += 1;
		do_map(data);
	}
	else if (data->map[data->pers_y][data->pers_x] == 'E' && data->collectible == data->nbr_collectible)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

void	put_img(t_data *data, int w, int h, char *textures)
{
	data->image.img = mlx_xpm_file_to_image(data->mlx_ptr, textures, &data->image.width, &data->image.height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img, w, h);
	mlx_destroy_image(data->mlx_ptr, data->image.img);
}

void	do_map(t_data *data)
{
	int	i;
	int	j;
	int	w;
	int	h;
	int	n_line = data->n_line;
	int	s_line = data->size_l;
//	int color;

//	color = 0xFFFFFFF;
	j = 0;
	while (j < n_line)
	{
		h = 64 * j;
		i = 0;
		while (i < s_line)
		{
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
			i++;
		}
		j++;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 60, 0xff0000, "Moves :");
	data->nbr_pas_aff = ft_itoa(data->nbr_pas);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 75, 60, 0xff0000, data->nbr_pas_aff);
	free(data->nbr_pas_aff);
}




int try(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->x, data->y, "VIDEO GAME");
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
	// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_map(data->map);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int main(int ac, char **av)
{
	t_img	test;
	t_data	data;

	char **error;

	error = parse(av);
	if (ac == 2)
	{
		if (error == NULL || check_size_line(av) == 1)
		{
			printf("Error: the map has incorrect characters or it is not rectangular\n");
			free_map(error);
			return (0);
		}
		free_map(error);
		data.map = parse(av);
		init_img(&test);
		init_data(&data, av);
		try(&data);
	}
	else
		printf("Error: usage: ./so_long <map.ber>\n");
	return (0);
}