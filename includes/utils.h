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

#ifndef UTILS_H
# define UTILS_H

# include "global.h"

char	*ft_cpy_w_malloc(char *str);
char	**ft_split(char *str, char *separator);
void	ft_split_second_part(char *str, char *sep, char **tab, int curr_str);
int		ft_is_sep(char to_test, char *str_sep);
char	*ft_strconcat(char *s1, char *s2);

#endif
