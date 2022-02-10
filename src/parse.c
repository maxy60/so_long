/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:57:41 by msainton          #+#    #+#             */
/*   Updated: 2022/02/10 17:21:47 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_elem(int c, int e)
{
	if (c < 1)
		return (1);
	if (e != 2)
		return (1);
	return (0);
}

int	check_element(t_data *data)
{
	int		i;
	int		j;
	int		c;
	int		e;
	char	*str;

	i = 0;
	e = 0;
	c = 0;
	while (i < data->n_line - 1)
	{
		j = 0;
		while (data->map[i][j])
		{
			str = data->map[i];
			if (str[j] == 'C')
				c++;
			if (str[j] == 'P' || str[j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	return (count_elem(c, e));
}

int	check_map(t_data *data)
{
	int		i;

	i = 1;
	while (i <= data->n_line - 1)
	{
		if (data->map[i][0] != '1'
				|| data->map[i][data->size_l - 1] != '1')
			return (1);
		i++;
	}
	if (check_map2(data) == 1)
		return (1);
	return (0);
}

char	**parse(char **av)
{
	char	**map;
	int		fd;
	int		l;

	l = 0;
	fd = 0;
	map = (char **)malloc(sizeof(char *) * (nbr_line(av) + 1));
	if (!map)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error\n", 2);
	while (l < nbr_line(av))
	{
		map[l] = get_next_line(fd);
		l++;
	}
	map[l] = NULL;
	close(fd);
	return (map);
}

int	collectible(t_data *data)
{
	int	i;
	int	j;
	int	c;

	j = 0;
	c = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				c++;
			i++;
		}
		j++;
	}
	return (c);
}
