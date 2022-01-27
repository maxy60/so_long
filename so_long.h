/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:51:44 by msainton          #+#    #+#             */
/*   Updated: 2022/01/27 16:27:14 by msainton         ###   ########.fr       */
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

# define SIZE_IMG 64
# define MLX_ERROR 1

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
    int     x;
    int     y;
	t_img	mob_face;
}   t_data;

char    *stock_line(char *dest, int ret);
char    *stock_rest(char *dest);
char    *ft_error(char *dest);
char    *get_next_line(int fd);
char	*ft_strjoin_g(const char *s1, const char *s2);
int		n_line(char **av);
int     size_line(char **av);
char	**parse(char **av);
int     main(int ac, char **av);

#endif
