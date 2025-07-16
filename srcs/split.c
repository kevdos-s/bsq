/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:54:00 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 22:56:48 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_utils.h"

char	**ft_split(char *str, char *separator)
{
	char	**tab;
	int		size_tab;

	size_tab = ft_count_multi_sep(str, separator);
	tab = (char **)malloc(size_tab * sizeof(char *));
	ft_split_second_part(str, separator, tab, 0);
	return (tab);
}

static void	copy_to_tab(char *src, char *dest, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
		dest[i++] = src[start++];
	dest[i] = '\0';
}

void	ft_split_second_part(char *str, char *sep, char **tab, int curr_str)
{
	int	l_start_pos;
	int	l_current_index_tab;

	l_start_pos = 0;
	l_current_index_tab = 0;
	while (str[curr_str] != '\0')
	{
		if (ft_is_sep(str[curr_str], sep) || str[curr_str + 1] == '\0')
		{
			if (str[curr_str + 1] == '\0')
				curr_str++;
			tab[l_current_index_tab] = malloc((curr_str - l_start_pos + 1)
					* sizeof(char));
			copy_to_tab(str, tab[l_current_index_tab], l_start_pos, curr_str);
			if (str[curr_str] == '\\' && str[curr_str + 1] == 'n')
			{
				l_start_pos++;
				curr_str++;
			}
			l_start_pos++;
			l_current_index_tab++;
		}
		curr_str++;
	}
}
