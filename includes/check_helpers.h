/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 21:10:06 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_HELPERS_H
# define CHECK_HELPERS_H

# include "check.h"
# include "global.h"
# include "map_creator.h"
# include "str_utils.h"
# include <stdio.h>

int		my_seek(int file_d, int offset);
int		get_line_length(int file_d);
void	read_first_line(int file_d, int line_len, t_map *map);
int		read_first_grid_line(int file_d, t_map *map);

#endif
