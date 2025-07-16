/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:19 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 20:23:01 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "solve.h"
#include "str_utils.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		nb_map;
	int		current;

	// prendre l'entree sur le terminal
	if (argc == 1)
	{
		map = (t_map *)malloc(1 * sizeof(t_map *));
		ft_check_n_fill_content(0, &map[0]);
		ft_print_map(&map[0], 0);
		solve(&map[0]);
		ft_print_map(&map[0], 1);
		ft_print_map(&map[0], 0);
		return (0);
	}
	nb_map = argc - 1;
	map = (t_map *)malloc(nb_map * sizeof(t_map *));
	ft_check_args_n_fill(argv, argc, &map);
	current = 0;
	while (current < nb_map)
	{
		if (map[current].is_valid)
		{
			// ft_print_map(map, 0);
			solve(&map[current]);
			// ft_print_map(map, 1);
			ft_print_map(map, 0);
		}
		else
			ft_error(ERROR_MAP_MSG);
		current++;
	}
}
