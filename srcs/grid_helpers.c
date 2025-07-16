/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:43:37 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 22:10:14 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "solve.h"
#include "stdlib.h"

void	init_map_tables(t_map *map)
{
	int	i;
	int	j;

	map->map = malloc(map->size_row * sizeof(char *));
	map->dp_map = malloc(map->size_row * sizeof(int *));
	i = 0;
	while (i < map->size_row)
	{
		map->map[i] = malloc(map->size_col * sizeof(char));
		map->dp_map[i] = malloc(map->size_col * sizeof(int));
		i++;
	}
	j = 0;
	i = 0;
	while (i < map->size_row)
	{
		j = 0;
		while (j < map->size_col)
		{
			map->map[i][j] = map->empty_char;
			map->dp_map[i][j] = i == 0 || j == 0;
			j++;
		}
		i++;
	}
}

int	fill_table_line(int row, char *grid_line, t_map *map)
{
	int	j;

	j = 0;
	while (j < map->size_col)
	{
		if (!is_valid_grid_char(grid_line[j], map))
		{
			map->is_valid = 0;
			return (0);
		}
		map->map[row][j] = grid_line[j];
		j++;
	}
	return (1);
}

int	fill_table(int file_d, t_map *map)
{
	char	*content;
	int		i;

	init_map_tables(map);
	content = malloc((map->size_col + 1) * sizeof(char));
	i = 0;
	while ((read(file_d, content, map->size_col + 1)) > 0 && i < map->size_row)
	{
		if (content[map->size_col] != '\n')
		{
			map->is_valid = 0;
			free(content);
			return (0);
		}
		if (!fill_table_line(i, content, map))
		{
			free(content);
			return (0);
		}
		i++;
	}
	free(content);
	return (i == map->size_row);
}

int	init_dp_ctx(t_dp_ctx **dp_ctx)
{
	*dp_ctx = malloc(sizeof(t_dp_ctx));
	if (!*dp_ctx)
		return (0);
	(*dp_ctx)->max_size = 0;
	(*dp_ctx)->max_i = 0;
	(*dp_ctx)->max_j = 0;
	return (1);
}
