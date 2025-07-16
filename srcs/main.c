/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:19 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 22:18:36 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "free.h"
#include "solve.h"
#include "str_utils.h"

void	compute_file_input(int nb_map, t_map *map)
{
	int	current;

	current = 0;
	while (current < nb_map)
	{
		if (!map[current].is_valid)
		{
			ft_putstr_error(ERROR_MAP_MSG);
			continue ;
		}
		solve(&map[current]);
		ft_print_map(map, 0);
		current++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = (t_map *)malloc((argc - (argc > 1)) * sizeof(t_map *));
	if (!map)
		return (0);
	if (argc == 1)
	{
		ft_check_n_fill_content(0, &map[0]);
		solve(&map[0]);
		ft_print_map(&map[0], 0);
	}
	else
	{
		ft_check_args_n_fill(argv, argc, &map);
		compute_file_input(argc - 1, map);
	}
}
