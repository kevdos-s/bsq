/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/15 17:00:26 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GLOBAL_H
# define GLOBAL_H

typedef struct s_point{
	int row;
	int col;
} t_point;

typedef struct s_map{
	int size_row;
	int size_col;
	char empty_char;
	char obstacle_char;
	char fill_char;
	char **map;
} t_map;


#include <stdlib.h>
#include <unistd.h>

#endif
