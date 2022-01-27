#include "../so_long.h"

/*void	init_img(t_img *test)
{
	test->img = NULL;
	test->width = 0;
	test->height = 0;
}*/

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
	
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)data;
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

/*int put_img(t_data *data)
{
	data->mob_face.img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/mob_face.xpm", &data->mob_face.width, &data->mob_face.height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mob_face.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->mob_face.img);
}

int	do_map(t_data *data, char **av)
{
	int	i;
	char **map;

	i = 0;
	map = parse(av);
	while (map[0][i])
	{
		if (map[0][i] != 1)
			return (-1);
		else
			put_img(data);
		i++;
	}
}*/

void	create_window(t_data *data, char **av)
{
	data->x = size_line(av) * SIZE_IMG;
	data->y = n_line(av) * SIZE_IMG;
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
	//do_map(data);
	//data->mob_face.img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/mob_face.xpm", &data->mob_face.width, &data->mob_face.height);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mob_face.img, 0, 0);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, data);
	mlx_loop(data->mlx_ptr);

	//mlx_destroy_image(data->mlx_ptr, data->mob_face.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int main(int ac, char **av)
{
	//t_img	test;
	t_data	data;
	//init_img(&test);
	if (ac == 2)
	{
		parse(av);
		try(&data, av);
	}
	else
		printf("Error: usage: ./so_long <map.ber>\n");
	return (0);
}