/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:57:41 by msainton          #+#    #+#             */
/*   Updated: 2022/01/28 17:19:57 by msainton         ###   ########.fr       */
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