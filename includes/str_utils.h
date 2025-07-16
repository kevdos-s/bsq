/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 18:58:22 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTILS_H
# define STR_UTILS_H

# include "global.h"

char	*ft_strdup(char *dest, char *src);
int		ft_count_sep(char *str, char sep);
int		ft_natoi(char *str, int limit);
int		ft_count_nb(char *str);
void	ft_print_map(t_map *map, int print_dp);
void	ft_print_map(t_map *map, int print_dp);
int		ft_is_sep(char to_test, char *str_sep);
int		ft_count_multi_sep(char *str, char *sep);

#endif
