/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:38:26 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/15 20:16:44 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void fill_map(char *content_file, t_map *map)
{
	char **lines_of_file;
	int nb_lines;
	int current_line;
	int i;
	int current_map_row;

	current_map_row = 0;
	nb_lines = ft_count_sep(content_file, '\n');
	lines_of_file = ft_split(content_file, '\n');
	current_line = 1;
	//TODO check first line is correct

	map->size_row = lines_of_file[0][0];
	map->empty_char = lines_of_file[0][1];
	map->obstacle_char = lines_of_file[0][2];
	map->fill_char = lines_of_file[0][3];


	map->size_col = ft_strlength(lines_of_file[1]) - 1;

	//fill the map
	map->map = (char *)malloc(map->size_row * sizeof(char *));

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


}
