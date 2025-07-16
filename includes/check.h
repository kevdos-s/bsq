/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 21:49:52 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "global.h"

void	ft_check_args_n_fill(char **args, int argc, t_map **map);
void	ft_check_n_fill_content(int file_d, t_map *map);
void	init_map_tables(t_map *map);
int		fill_table_line(int row, char *grid_line, t_map *map);

#endif
