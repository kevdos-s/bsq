/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:58:31 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 21:55:23 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "check_helpers.h"
#include "grid_helpers.h"
#include "map_creator.h"
#include "str_utils.h"
#include <stdio.h>

int	is_valid_grid_char(char c, t_map *map)
{
	return (c != map->empty_char || c != map->obstacle_char);
}

void	set_parameters(int first_line_len, int current, char *path, t_map **map)
{
	int	file_d;

	file_d = open(path, O_RDONLY);
	read_first_line(file_d, first_line_len, map[current]);
	my_seek(file_d, 1);
	read_first_grid_line(file_d, map[current]);
	close(file_d);
	file_d = open(path, O_RDONLY);
	my_seek(file_d, first_line_len + 1);
}

void	ft_check_args_n_fill(char **args, int argc, t_map **map)
{
	int	current;
	int	file_d;
	int	first_line_len;

	current = 0;
	while ((current + 1) < argc)
	{
		file_d = open(args[(current + 1)], O_RDONLY);
		map[current] = malloc(sizeof(t_map));
		if (file_d == -1)
		{
			map[current]->is_valid = 0;
			continue ;
		}
		first_line_len = get_line_length(file_d);
		close(file_d);
		set_parameters(first_line_len, current, args[(current + 1)], map);
		map[current]->is_valid = fill_table(file_d, map[current]);
		current++;
	}
}

void	ft_check_n_fill_content(int file_d, t_map *map)
{
	int		byte_read;
	char	content[4096];
	char	*all_content;

	byte_read = read(file_d, content, 1);
	while (byte_read > 0)
	{
		if (content[0] == '\n')
			break ;
		byte_read = read(file_d, content, 1);
	}
	all_content = malloc(1 * sizeof(char));
	all_content[0] = '\0';
	if (byte_read == -1)
	{
		map->is_valid = 0;
		return ;
	}
	fill_map(all_content, map);
	free(all_content);
}
