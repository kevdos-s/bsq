/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:38:26 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 22:29:32 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "map_creator.h"
#include "str_utils.h"

void	fill_map(char *content_file, t_map *map)
{
	char	**lines_of_file;
	int		nb_lines;
	int		i;
	int		current_map_row;

	current_map_row = 0;
	nb_lines = ft_count_multi_sep(content_file, "\n\\");
	lines_of_file = ft_split(content_file, "\n\\");
	ft_fill_first_line(lines_of_file[0], map);
	map->size_col = ft_strlength(lines_of_file[1]);
	map->map = malloc(map->size_row * sizeof(char *));
	while ((current_map_row + 1) < nb_lines)
	{
		map->map[current_map_row] = malloc(map->size_col * sizeof(char));
		i = 0;
		while (lines_of_file[current_map_row + 1][i])
		{
			map->map[current_map_row][i] = lines_of_file[current_map_row
				+ 1][i];
			i++;
		}
		current_map_row++;
	}
	map->is_valid = 1;
}

void	ft_fill_first_line(char *first_line, t_map *map)
{
	int	len_str;
	int	diff;

	len_str = ft_strlength(first_line);
	diff = len_str - 3;
	map->size_row = ft_natoi(first_line, diff);
	map->empty_char = first_line[len_str - 3];
	map->obstacle_char = first_line[len_str - 2];
	map->fill_char = first_line[len_str - 1];
}
