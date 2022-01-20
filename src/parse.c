/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:57:41 by msainton          #+#    #+#             */
/*   Updated: 2022/01/20 18:12:28 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialise(t_map *map)
{
	map->c = 0;
	map->l = 0;
}

void	size_map(int fd, t_map *map)
{
	char *line;
	int count;
	
	line = get_next_line(fd);
	map->c = ft_strlen(line);
	count = 1;
	while (get_next_line(fd) != NULL)
		count++;
	printf("count = %d\n", count);
	map->l = count;
}