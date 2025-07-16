/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:58:31 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 16:33:07 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "map_creator.h"
#include "str_utils.h"

void	ft_check_args_n_fill(char **args, int argc, t_map **map)
{
	int		current;
	int		current_argv;
	int		file_d;
	int		byte_read;
	char	*content;
	char	*all_content;
	char	*temp;

	current = 0;
	current_argv = 1;
	while (current_argv < argc)
	{
		file_d = open(args[current_argv], O_RDONLY);
		map[current] = malloc(sizeof(t_map));
		if (file_d == -1)
		{
			map[current]->is_valid = 0;
		}
		else
		{
			all_content = malloc(1 * sizeof(char));
			all_content[0] = '\0';
			content = malloc(25005008 * sizeof(char));
			while ((byte_read = read(file_d, content, 25005008)) > 0)
			{
				temp = ft_cpy_w_malloc(all_content);
				free(all_content);
				all_content = ft_strdup(temp, content);
				free(temp);
			}
			if (byte_read == -1)
			{
				map[current]->is_valid = 0;
				return ;
			}
			fill_map(all_content, map[current]);
			// free(all_content);
		}
		close(file_d);
		current++;
		current_argv++;
	}
}

void	ft_check_n_fill_content(int file_d, t_map *map)
{
	int		byte_read;
	char	*content;
	char	*all_content;
	char	*temp;

	all_content = malloc(1 * sizeof(char));
	all_content[0] = '\0';
	content = malloc(4096 * sizeof(char));
	while ((byte_read = read(file_d, content, 4096)) > 0)
	{
		temp = ft_cpy_w_malloc(all_content);
		free(all_content);
		all_content = ft_strdup(temp, content);
		free(temp);
	}
	if (byte_read == -1)
	{
		map->is_valid = 0;
		return ;
	}
	fill_map(all_content, map);
	free(all_content);
}
