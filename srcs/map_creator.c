/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:38:26 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 18:44:11 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "map_creator.h"
#include "str_utils.h"

void	fill_map(char *content_file, t_map *map)
{
	char	**lines_of_file;
	int		nb_lines;
	int		current_line;
	int		i;
	int		current_map_row;

	current_map_row = 0;
	nb_lines = ft_count_multi_sep(content_file, "\n\\");
	lines_of_file = ft_split(content_file, "\n\\");
	current_line = 1;
	// TODO check first line is correct
	ft_fill_first_line(lines_of_file[0], map);
	map->size_col = ft_strlength(lines_of_file[1]);
	// fill the map
	map->map = malloc(map->size_row * sizeof(char *));
	while (current_line < nb_lines)
	{
		map->map[current_map_row] = malloc(map->size_col * sizeof(char));
		i = 0;
		while (lines_of_file[current_line][i])
		{
			map->map[current_map_row][i] = lines_of_file[current_line][i];
			i++;
		}
		current_line++;
		current_map_row++;
	}
	map->is_valid = 1;
}
void	ft_fill_first_line(char *first_line, t_map *map)
{
	int	index_nb_stop;

	index_nb_stop = ft_count_nb(first_line);
	map->size_row = ft_atoi(first_line);
	map->empty_char = first_line[index_nb_stop];
	map->obstacle_char = first_line[index_nb_stop + 1];
	map->fill_char = first_line[index_nb_stop + 2];
}
