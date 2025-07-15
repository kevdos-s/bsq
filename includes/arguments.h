/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:44:17 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/15 19:47:51 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

char	**get_map_from_std_input(void);
t_map	*get_map_from_path(char *path);

#endif