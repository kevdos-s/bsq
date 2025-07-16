/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:43:37 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 16:33:07 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "stdlib.h"

/**
 * Frees the dynamically allocated memory for the DP grid.
 *
 * This function frees every row of the DP grid and then
 * frees the pointer to the first row of the DP grid.
 *
 * @param map_ctx A pointer to the map context structure,
	which contains the DP grid.
 */
void	free_dp_grid(t_map *map_ctx)
{
	int	i;

	i = 0;
	while (i < map_ctx->size_row)
	{
		// free(map_ctx->dp_map[i]);
		i++;
	}
	// free(map_ctx->dp_map);
}
