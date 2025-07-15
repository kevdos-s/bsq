/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:58:31 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/15 20:58:10 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "map_creator.h"
#include "str_utils.h"

void	ft_check_args_n_fill(char **args, int argc, t_map **map)
{
	int	current;
	int	current_argv;
	int	file_d;

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
			ft_check_n_fill_content(file_d, map[current]);
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
}
