/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_helpers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 20:58:15 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_HELPERS_H
# define GRID_HELPERS_H

# include "global.h"
# include "solve.h"

void	init_dp_grid(t_map *map_ctx);
void	init_dp_ctx(t_dp_ctx **dp_ctx);

#endif
