/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/15 20:41:51 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

typedef struct s_point
{
	int		row;
	int		col;
}			t_point;

typedef struct s_map
{
	int		size_row;
	int		size_col;
	char	empty_char;
	char	obstacle_char;
	char	fill_char;
	int		**dp_map;
	char	**map;
}			t_map;

#endif
