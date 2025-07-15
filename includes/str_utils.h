/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/15 20:59:18 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CREATOR_H
# define MAP_CREATOR_H

# include "global.h"

void	fill_map(char *content_file, t_map *map);
char	*ft_strdup(char *dest, char *src);
int		ft_count_sep(char *str, char sep);

#endif
