/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:51:44 by msainton          #+#    #+#             */
/*   Updated: 2022/01/24 15:43:54 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR 1

typedef struct s_map
{
    int     l;
    int     c;
    char    *line;
}   t_map;

char    *stock_line(char *dest, int ret);
char    *stock_rest(char *dest);
char    *ft_error(char *dest);
char    *get_next_line(int fd);
char	*ft_strjoin_g(const char *s1, const char *s2);
void	initialise(t_map *map);
int		n_line(char **av);
char	**parse(char **av);
int     main(int ac, char **av);

#endif
