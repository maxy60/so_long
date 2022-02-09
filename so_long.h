/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:51:44 by msainton          #+#    #+#             */
/*   Updated: 2022/02/09 14:34:12 by msainton         ###   ########.fr       */
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
	char	**map;
	int		pers_x;
	int		pers_y;
	int		size_l;
	int		n_line;
    int     x;
    int     y;
	int		collectible;
	int		nbr_collectible;
	int		nbr_pas;
	char	*nbr_pas_aff;
	t_img	image;
}   t_data;

char    *stock_line(char *dest);
char    *stock_rest(char *dest);
char    *ft_error(char *dest);
char    *get_next_line(int fd);
char	*ft_strjoin_g(const char *s1, const char *s2);
int		nbr_line(char **av);
int     size_line(char **av);
void	free_map(char **map);
void	put_img(t_data *data, int w, int h, char *textures);

void	pos_perso(t_data *data);
int		collectible(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

int		check_size_line(char **map, char **av);
int		wall(t_data *data);
int		check_map(t_data *data);
int		check_element(t_data *data);

void	print_map(t_data *data);

void	do_map(t_data *data);
char	**parse(char **av);
int     main(int ac, char **av);

#endif
