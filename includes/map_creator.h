/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:35:59 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 13:31:45 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CREATOR_H
# define MAP_CREATOR_H

# include "global.h"

void	fill_map(char *content_file, t_map *map);
void	ft_fill_first_line(char *first_line, t_map *map);

#endif
