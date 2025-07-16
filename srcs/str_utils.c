/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:55:25 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 21:40:27 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "print_utils.h"
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
		if (print_dp)
		{
			while (current_col < map->size_col)
			{
				if (print_dp)
					ft_putnb(map->dp_map[current_line][current_col]);
				current_col++;
			}
		}
		else
			print_line(map->map[current_line], map->size_col);
		ft_putchar('\n');
		current_line++;
	}
}
