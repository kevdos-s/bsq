/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:58:31 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 21:46:19 by apisanel         ###   ########.fr       */
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
		byte_read = read(file_d, content, 1);
		if (byte_read == -1)
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
	byte_read = read(file_d, content, 1);
	while (byte_read > 0)
	{
		if (content[0] == '\n')
			break ;
		byte_read = read(file_d, content, 1);
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
