#include "../so_long.h"

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

int handle_input(int keysym, t_data *data)
{
	if (keysym == 65307)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//else if (keysym == 119)
	//	perso_up();
	printf("Keypress: %d\n", keysym);
	return (0);
}

/*int	pos_perso(t_data *data, char **av)
{
	int		i;
	int		j;
	char	**map;
	int		n_line = nbr_line(av);

	j = 0;
	map = parse(av);
	while (j < n_line)
	{
		i = 0;
		while (i != 'P')
			i++;
		j++;
	}
	int w = i * 64;
	int h = (j - 1) * 64;
	put_img(data, w, h, "./textures/perso_back.XPM");
	free_map(map);
	return (0);
}*/

void	put_img(t_data *data, int w, int h, char *textures)
{
	data->image.img = mlx_xpm_file_to_image(data->mlx_ptr, textures, &data->image.width, &data->image.height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img, w, h);
	mlx_destroy_image(data->mlx_ptr, data->image.img);
}

int	do_map(t_data *data, char **av)
{
	int	i;
	int	j;
	int	w;
	int	h;
	char **map;
	int	n_line = nbr_line(av);
	int	s_line = size_line(av);

	j = 0;
	map = parse(av);
	while (j < n_line)
	{
		h = 64 * j;
		i = 0;
		while (i < s_line)
		{
			w = 64 * i;
			if (map[j][i] == '0')
				put_img(data, w, h, "./textures/floor.XPM");
			else if (map[j][i] == '1')
				put_img(data, w, h, "./textures/trap.XPM");
			else if (map[j][i] == 'P')
				put_img(data, w, h, "./textures/perso_face.XPM");
			else if (map[j][i] == 'C')
				put_img(data, w, h, "./textures/item.XPM");
			else if (map[j][i] == 'E')
				put_img(data, w, h, "./textures/exit.XPM");
			i++;
		}
		j++;
	}
	free_map(map);
	return (0);
}



void	create_window(t_data *data, char **av)
{
	data->x = size_line(av) * SIZE_IMG;
	data->y = nbr_line(av) * SIZE_IMG;
}

int try(t_data *data, char **av)
{
	create_window(data, av);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->x, data->y, "VIDEO GAME");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	do_map(data, av);
	//pos_perso(data, av);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_loop(data->mlx_ptr);

	//mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int main(int ac, char **av)
{
	t_img	test;
	t_data	data;
	init_img(&test);
	if (ac == 2)
	{
		//parse(av);
		try(&data, av);
	}
	else
		printf("Error: usage: ./so_long <map.ber>\n");
	return (0);
}