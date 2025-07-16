/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_helpers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 21:53:53 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_HELPERS_H
# define GRID_HELPERS_H

# include "global.h"
# include "solve.h"

void	init_map_tables(t_map *map);
int		fill_table_line(int row, char *grid_line, t_map *map);
int		fill_table(int file_d, t_map *map);
int		init_dp_ctx(t_dp_ctx **dp_ctx);

#endif
