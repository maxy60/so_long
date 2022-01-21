/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:57:41 by msainton          #+#    #+#             */
/*   Updated: 2022/01/21 16:54:10 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	n_line(char **av)
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
		if (buf[0] == '\n')
			count++;
	}
	close(fd);
	return (count);
}

void	parse(char **av)
{
	char *line;
	int fd = 0;
	int l;
	
	l = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error\n", 2);
	while (l < n_line(av))
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		l++;
	}
	close(fd);
}