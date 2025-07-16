/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:58:31 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 21:17:06 by kevdos-s         ###   ########.fr       */
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

	// int		backslash;
	// backslash = 0;
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
	map->is_valid = line_len > 3 || ('0' < content[0] && content[0] <= '9');
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

int	is_valid_grid_char(char c, t_map *map)
{
	return (c != map->empty_char || c != map->obstacle_char);
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
		map[current] = malloc(sizeof(t_map));
		first_line_len = get_line_length(file_d);
		if (file_d == -1)
		{
			map[current]->is_valid = 0;
			continue ;
		}
		// else
		// {
		// 	ft_check_n_fill_content(file_d, map[current]);
		// }
		close(file_d);
		file_d = open(args[current_argv], O_RDONLY);
		read_first_line(file_d, first_line_len, map[current]);
		my_seek(file_d, 1);
		read_first_grid_line(file_d, map[current]);
		close(file_d);
		file_d = open(args[current_argv], O_RDONLY);
		my_seek(file_d, first_line_len + 1);
		if (!fill_table(file_d, map[current]))
		{
			// TODO: map error;
			map[current]->is_valid = 0;
		}
		else
			map[current]->is_valid = 1;
		// fill_map(all_content, map);
		current_argv++;
		current++;
	}
}

void	ft_check_n_fill_content(int file_d, t_map *map)
{
	int		byte_read;
	char	content[4096];
	char	*all_content;
	char	*temp;

	all_content = malloc(1 * sizeof(char));
	all_content[0] = '\0';
	while ((byte_read = read(file_d, content, 4096)) > 0)
	{
		if (content[0] == '\0')
		{
			map->is_valid = 0;
			return ;
		}
		temp = ft_cpy_w_malloc(all_content);
		free(all_content);
		all_content = ft_strconcat(temp, content);
		free(temp);
	}
	// i += 1;
	if (byte_read == -1)
	{
		map->is_valid = 0;
		free(all_content);
		return ;
	}
	fill_map(all_content, map);
	free(all_content);
}
