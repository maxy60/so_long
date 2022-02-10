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
}

int	files_name(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	while (str[i] != '.' || i == j)
		i++;
	if (i == 0 || str[i - 1] == '/')
		return(1);
	if (i + 4 != j)
		return (1);
	if (str[i + 1] != 'b' || str[i + 2] != 'e' || str[i + 3] != 'r')
		return (1);
	return (0);
}

int	if_is_file(char *str)
{
	int fd;
	
	fd = open(str, O_DIRECTORY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	ft_putstr_fd("it is not a file\n", 2);
	close(fd);
	return (1);
}

int	check_file(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("files cannot be read\n", 2);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	t_img	test;
	t_data	data;

	if (ac == 2 && check_file(av[1]) == 0 && files_name(av[1]) == 0 && if_is_file(av[1]) == 0)
	{
		data.map = parse(av);
		init_data(&data, av);
		if (data.map == NULL || check_size_line(data.map, av) == 1 || wall(&data) == 1 || check_map(&data) == 1 || check_element(&data) == 1)
		{
			printf("Error: the map has incorrect characters or it is not rectangular\n");
			free_map(data.map);
			return (0);
		}
		init_img(&test);
		try(&data);
	}
	else
		printf("Error: usage: ./so_long <map.ber>\n");
	return (0);
}
