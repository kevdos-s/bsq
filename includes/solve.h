/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 11:41:30 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

#ifndef SOLVE_H
# define SOLVE_H

typedef struct s_min_ctx
{
	t_map	*t_map;
	int		row;
	int		col;
	int		*min_arr;
	int		*max_size;
	int		*max_i;
	int		*max_j;
}			t_min_ctx;

void	solve(t_map *map_ctx, int *max_size, int *max_i, int *max_j);
#endif
