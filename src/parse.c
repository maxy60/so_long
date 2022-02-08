/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:57:41 by msainton          #+#    #+#             */
/*   Updated: 2022/02/08 19:07:02 by msainton         ###   ########.fr       */
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
	count = 1;
	fd = open(av[1], O_RDONLY);
	while (ret > 0)
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
			return (-1);
		if (buf[0] == '\n' || buf[0] == '\0')
			count++;
	}
	close(fd);
	return (count);
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
	return (count - 1);
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

int check_size_line(char **av)
{
	char	**map;
	int s_line;
	int	l;
	int size_l;
	int	n_line;

	l = 1;
	n_line = nbr_line(av);
	s_line = size_line(av);
	map = parse(av);
	while (l < n_line - 1)
	{
		size_l = ft_strlen(map[l]) - 1;
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

int check_map(char *str)
{
	int	i;
	
	i = 0;
	if (str[0] != '1' || str[ft_strlen(str) - 2] != '1')
		return (1);
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'P' && str[i] != 'C' && str[i] != 'E' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

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
		if (check_map(map[l]) == 1)
		{
			free_map(map);
			return (NULL);
		}
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