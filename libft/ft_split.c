/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:08:21 by msainton          #+#    #+#             */
/*   Updated: 2021/10/07 18:53:19 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **tab)
{
	size_t	a;

	a = 0;
	while (tab[a])
	{
		free(tab[a]);
		a++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, char c)
{
	size_t	a;
	size_t	nb_strs;

	if (!s)
		return (0);
	a = 0;
	nb_strs = 0;
	while (s[a] && s[a] == c)
		a++;
	if (s[a] == '\0')
		return (0);
	while (s[a])
	{
		if (s[a] == c)
		{
			nb_strs++;
			while (s[a] && s[a] == c)
				a++;
			continue ;
		}
		a++;
	}
	if (s[a - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void	ft_get_next_str(char **next_str, size_t *next_str_len,
					char c)
{
	size_t	a;

	*next_str += *next_str_len;
	*next_str_len = 0;
	a = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[a])
	{
		if ((*next_str)[a] == c)
			return ;
		(*next_str_len)++;
		a++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**dest;
	char			*next_str;
	size_t			next_str_len;
	size_t			nb_strs;
	size_t			a;

	if (!s)
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	dest = (char **)malloc(sizeof(char *) * (nb_strs + 1));
	if (!dest)
		return (NULL);
	a = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (a < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		dest[a] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!dest)
			return (ft_malloc_error(dest));
		ft_strlcpy(dest[a++], next_str, next_str_len + 1);
	}
	dest[a] = NULL;
	return (dest);
}
