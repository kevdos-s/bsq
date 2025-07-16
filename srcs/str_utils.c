/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:55:25 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 18:58:57 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include <stdlib.h>

int	ft_strlength(char *str)
{
	int	current;

	current = 0;
	while (str[current])
	{
		current++;
	}
	return (current);
}

char	*ft_strdup(char *dest, char *src)
{
	int		current;
	int		len_dest;
	int		result_len;
	char	*result;

	len_dest = ft_strlength(dest);
	result_len = len_dest + ft_strlength(src);
	result = malloc(result_len * sizeof(char));
	current = 0;
	while (dest[current])
	{
		result[current] = dest[current];
		current++;
	}
	current = 0;
	while (src[current])
	{
		result[len_dest] = src[current];
		current++;
		len_dest++;
	}
	result[len_dest] = '\0';
	return (result);
}

int	ft_count_sep(char *str, char sep)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == sep || str[i + 1] == '\0')
		{
			result++;
		}
		i++;
	}
	return (result);
}

int	ft_count_multi_sep(char *str, char *sep)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], sep) || str[i + 1] == '\0')
		{
			result++;
		}
		if (str[i] == '\\' && str[i + 1] == 'n')
			i++;
		i++;
	}
	return (result);
}
int	ft_natoi(char *str, int limit)
{
	int	result;
	int	current;

	result = 0;
	current = 0;
	while ((str[current] >= '0' && str[current] <= '9') && current < limit)
	{
		result = (result * 10) + (str[current] - 48);
		current++;
	}
	return (result);
}
int	ft_count_nb(char *str)
{
	int	current;

	current = 0;
	while (str[current] >= '0' && str[current] <= '9')
	{
		current++;
	}
	return (current);
}
void	ft_print_map(t_map *map, int print_dp)
{
	int	current_line;
	int	current_col;

	current_line = 0;
	while (current_line < map->size_row)
	{
		current_col = 0;
		while (current_col < map->size_col)
		{
			if (print_dp)
			{
				ft_putnb(map->dp_map[current_line][current_col]);
			}
			else
			{
				ft_putchar(map->map[current_line][current_col]);
			}
			current_col++;
		}
		ft_putchar('\n');
		current_line++;
	}
}
