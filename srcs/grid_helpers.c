/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:43:37 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 13:49:13 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include "stdlib.h"

/**
 * Allocates memory for the dynamic programming (DP) grid in the map context.
 *
 * This function initializes the dp_map field of the map_ctx structure,
 * allocating enough memory for a 2D grid with dimensions size_row x size_col.
 * Each element in the DP grid is an integer.
 * We set a fixed 1 value on the first row and column of the DP grid.
 *
 * @param map_ctx A pointer to the map context structure which holds the DP grid
 *                and related map information.
 */

void	init_dp_grid(t_map *map_ctx)
{
	int	i;
	int	j;

	map_ctx->dp_map = malloc(sizeof(int *) * map_ctx->size_row);
	if (map_ctx->dp_map == NULL)
		return ;
	i = 0;
	while (i < map_ctx->size_row)
	{
		map_ctx->dp_map[i] = malloc(sizeof(int) * map_ctx->size_col);
		if (map_ctx->dp_map[i] == NULL)
			return ;
		j = 0;
		while (j < map_ctx->size_col)
		{
			if (i == 0 || j == 0)
				map_ctx->dp_map[i][j] = 1;
			else
				map_ctx->dp_map[i][j] = 0;
			// TODO: refactor: map_ctx->dp_map[i][j] = i == 0 || j == 0;
			j++;
		}
		i++;
	}
}

int	init_dp_ctx(t_dp_ctx **dp_ctx)
{
	*dp_ctx = malloc(sizeof(t_dp_ctx));
	if (!*dp_ctx)
		return (0);
	(*dp_ctx)->max_size = 0;
	(*dp_ctx)->max_i = 0;
	(*dp_ctx)->max_j = 0;
	return (1);
}
