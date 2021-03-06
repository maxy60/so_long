/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:56:21 by msainton          #+#    #+#             */
/*   Updated: 2022/02/09 14:34:42 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check(char *str)
{
	size_t	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
	{
		if (str[a] == '\n')
			return (1);
		a++;
	}
	return (0);
}

char	*ft_error(char *dest)
{
	if (dest)
	{
		free(dest);
		dest = NULL;
	}
	return (NULL);
}

static char	*retgnl(char **dest, char *line, int ret)
{
	if (ret == 0)
	{
		free(*dest);
		*dest = NULL;
		if (line[0] == '\0')
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		return (line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*dest;
	char		*line;
	int			ret;

	ret = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, "", 0) != 0)
		return (ft_error(dest));
	if (!dest)
	{	
		dest = (char *)malloc(sizeof(char) * 1);
		dest[0] = '\0';
	}
	while (check(dest) == 0 && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (ft_error(dest));
		buf[ret] = '\0';
		dest = ft_strjoin(dest, buf);
	}
	line = stock_line(dest);
	dest = stock_rest(dest);
	return (retgnl(&dest, line, ret));
}
