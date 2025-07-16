/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:58:31 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 19:22:05 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "map_creator.h"
#include "str_utils.h"
#include <stdio.h>

int	my_seek(int file_d, int offset)
{
	int		byte_read;
	char	content[1];

	while (offset > 0)
	{
		if ((byte_read = read(file_d, content, 1)) == -1)
			return (-1);
		offset--;
	}
	return (0);
}
int	get_line_length(int file_d)
{
	int		byte_read;
	char	content[1];
	int		i;

	i = 0;
	while ((byte_read = read(file_d, content, 1)) > 0)
	{
		if (content[0] == '\n')
			break ;
		i++;
	}
	return (i);
}

void	read_first_line(int file_d, int line_len, t_map *map)
{
	char	*content;

	content = malloc(line_len * sizeof(char));
	read(file_d, content, line_len);
	content[line_len] = '\0';
	ft_fill_first_line(content, map);
}

int	read_first_grid_line(int file_d, t_map *map)
{
	int	line_len;

	line_len = get_line_length(file_d);
	map->size_col = line_len;
	return (line_len);
}

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

void	fill_table(int file_d, t_map *map)
{
	char	*content;
	int		byte_read;
	int		i;
	int		j;

	init_map_tables(map);
	content = malloc((map->size_col + 1) * sizeof(char));
	i = 0;
	while ((byte_read = read(file_d, content, map->size_col + 1)) > 0)
	{
		j = 0;
		while (j < map->size_col)
		{
			map->map[i][j] = content[j];
			j++;
		}
		i++;
	}
	free(content);
}

void	ft_check_args_n_fill(char **args, int argc, t_map **map)
{
	int	current;
	int	current_argv;
	int	file_d;
	int	first_line_len;

	current = 0;
	current_argv = 1;
	while (current_argv < argc)
	{
		file_d = open(args[current_argv], O_RDONLY);
		first_line_len = get_line_length(file_d);
		close(file_d);
		file_d = open(args[current_argv], O_RDONLY);
		read_first_line(file_d, first_line_len, map[current]);
		my_seek(file_d, 1);
		read_first_grid_line(file_d, map[current]);
		close(file_d);
		file_d = open(args[current_argv], O_RDONLY);
		my_seek(file_d, first_line_len + 1);
		fill_table(file_d, map[current]);
		map[current]->is_valid = 1;
		current_argv++;
		current++;
	}
}

void	ft_check_n_fill_content(int file_d, t_map *map)
{
	int		byte_read;
	char	content[4096];
	char	*all_content;

	// char	*temp;
	// int		count_lines;
	// int		i;
	// i = 0;
	// count_lines = 0;
	while ((byte_read = read(file_d, content, 1)) > 0)
	{
		if (content[0] == '\n')
			break ;
		// i++;
	}
	// i += 1;
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
