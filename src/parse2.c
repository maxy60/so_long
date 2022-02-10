/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:17:14 by msainton          #+#    #+#             */
/*   Updated: 2022/02/10 16:23:54 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	nbr_line(char **av)
{
	char	buf[1];
	int		fd;
	int		count;
	int		ret;

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

int	size_line(char **av)
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
	int	i;

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

int	check_size_line(char **map, char **av)
{
	int	s_line;
	int	l;
	int	size_l;
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
