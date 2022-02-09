/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:57:41 by msainton          #+#    #+#             */
/*   Updated: 2022/02/09 16:08:05 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	nbr_line(char **av)
{
	char buf[1];
	int	fd;
	int count;
	int	ret;

	ret = 1;
	count = 0;
	fd = open(av[1], O_RDONLY);
	while (ret > 0)
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
			return (-1);
		if (buf[0] == '\n')
			count++;
	}
	close(fd);
	fflush(stdout);
	return (count - 1);
}

int		size_line(char **av)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line[count])
		count++;
	free(line);
	close(fd);
	return (count);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}

int	wall(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->size_l - 1)
	{
		if (data->map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i <= data->size_l - 1)
	{
		if (data->map[data->n_line - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}


int check_size_line(char **map, char **av)
{
	int s_line;
	int	l;
	int size_l;
	int	n_line;

	l = 1;
	n_line = nbr_line(av);
	s_line = size_line(av);
	while (l < n_line - 1)
	{
		size_l = ft_strlen(map[l]);
		if (size_l == s_line)
			l++;
		else
			return (1);		
	}
	size_l = ft_strlen(map[l]);
	if (size_l == s_line)
		return (0);
	else
		return (1);
}

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
	int	i;
	int	j;
	int	c;
	int	e;
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

int check_map(t_data *data)
{
	int	i;
	int	j;
	char	*str;
	
	i = 1;
	while (i <= data->n_line - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][data->size_l - 1] != '1')
		return (1);
		i++;
	}
	i = 0;
	j = 0;
	while (i < data->n_line - 1)
	{
		j = 0;
		while (data->map[i][j])
		{
			str = data->map[i];
			if (str[j] != '0' && str[j] != '1' && str[j] != 'P' && str[j] != 'C' && str[j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			printf("%c ", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}*/

char	**parse(char **av)
{
	char **map;
	int fd = 0;
	int l;

	l = 0;
	map = (char **)malloc(sizeof(char *) * (nbr_line(av) + 1));
	if (!map)
		return(NULL);
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
	int c;

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