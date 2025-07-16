/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:02:07 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 13:07:42 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void ft_free_t_map(t_map *map)
{

	int	i;

	i = 0;
	while (i < map->size_row)
	{
		free(map->dp_map[i]);
		free(map->map);
		i++;
	}
	free(map->dp_map);

}
