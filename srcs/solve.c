/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:43:37 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 14:58:09 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_helpers.h"
#include "grid_helpers.h"
#include "solve.h"
#include "stdlib.h"
#include <stdio.h>

void	get_min_dp_current_value(t_min_ctx min_ctx)
{
	int	min_value;

	min_value = min(min_ctx.min_arr, 3) + 1;
	min_ctx.t_map->dp_map[min_ctx.row][min_ctx.col] = min_value;
	if (min_value > *min_ctx.max_size)
	{
		*min_ctx.max_size = min_value;
		*min_ctx.max_i = min_ctx.row;
		*min_ctx.max_j = min_ctx.col;
	}
}

void	set_solution_to_map(t_map *map_ctx, t_dp_ctx *dp_ctx)
{
	int	i;
	int	j;

	i = dp_ctx->max_i - (dp_ctx->max_size - 1);
	j = dp_ctx->max_j - (dp_ctx->max_size - 1);
	while (i <= dp_ctx->max_i)
	{
		j = dp_ctx->max_j - (dp_ctx->max_size - 1);
		while (j <= dp_ctx->max_j)
		{
			map_ctx->map[i][j] = map_ctx->fill_char;
			j++;
		}
		i++;
	}
}

void	solve(t_map *map_ctx)
{
	int			i;
	int			j;
	int			min_arr[3];
	t_dp_ctx	*dp_ctx;

	dp_ctx = NULL;
	init_dp_grid(map_ctx);
	init_dp_ctx(&dp_ctx);
	i = 1;
	while (i < map_ctx->size_row)
	{
		j = 1;
		while (j < map_ctx->size_col)
		{
			if (map_ctx->map[i][j] == map_ctx->empty_char)
			{
				min_arr[0] = map_ctx->dp_map[i - 1][j];
				min_arr[1] = map_ctx->dp_map[i][j - 1];
				min_arr[2] = map_ctx->dp_map[i - 1][j - 1];
				get_min_dp_current_value((t_min_ctx){map_ctx, i, j, min_arr,
					&dp_ctx->max_size, &dp_ctx->max_i, &dp_ctx->max_j});
			}
			else
				map_ctx->dp_map[i][j] = 0;
			j++;
		}
		i++;
	}
	set_solution_to_map(map_ctx, dp_ctx);
}
