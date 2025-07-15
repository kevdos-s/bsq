/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:19 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/15 18:51:52 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int main(int argc, char **argv)
{
	t_map *map;
	int nb_map;
	//prendre l'entree sur le terminal
	if (argc == 1)
	{
		return (0);
	}
	nb_map = argc - 1;
	map = (t_map *)malloc(nb_map * sizeof(t_map *));
	ft_check_args_n_fill(argv, argc, &map);


}
