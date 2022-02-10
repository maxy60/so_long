/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:41:57 by msainton          #+#    #+#             */
/*   Updated: 2022/02/10 19:42:45 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		return (1);
	if (i + 4 != j)
		return (1);
	if (str[i + 1] != 'b' || str[i + 2] != 'e' || str[i + 3] != 'r')
		return (1);
	return (0);
}

int	if_is_file(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd < 0)
		return (0);
	ft_putstr_fd("it is not a file\n", 2);
	return (1);
}

int	check_file(char *str)
{
	int	fd;

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
