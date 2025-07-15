/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/15 19:55:31 by apisanel         ###   ########.fr       */
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

#endif
