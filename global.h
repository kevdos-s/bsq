/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/15 13:06:44 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GLOBAL_H
# define GLOBAL_H

typedef struct s_point{
	int line;
	int column;
} t_point;

typedef struct s_map{
	int size;
	char empty_char;
	char obstacle_char;
	char fill_char;
	char **map;
} t_map;

typedef struct s_list_point{
	t_point *previous;
	t_point *next;
	t_point *first;
	t_point *last;
	t_point current;
	int current_index;
} t_list_point;

#endif
