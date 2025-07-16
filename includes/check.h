/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 22:11:06 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "global.h"

int		is_valid_grid_char(char c, t_map *map);
void	set_parameters(int first_line_len, int current, char *path,
			t_map **map);
void	ft_check_args_n_fill(char **args, int argc, t_map **map);
void	ft_check_n_fill_content(int file_d, t_map *map);
int		is_valid_grid_char(char c, t_map *map);

#endif
