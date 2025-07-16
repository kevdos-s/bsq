/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:17:09 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 22:57:01 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_utils.h"

char	*ft_cpy_w_malloc(char *str)
{
	int		current;
	char	*result;
	int		len_str;

	len_str = ft_strlength(str);
	result = malloc(len_str * sizeof(char));
	if (len_str == 0)
		result[0] = '\0';
	current = 0;
	while (str[current])
	{
		result[current] = str[current];
		current++;
	}
	result[current] = '\0';
	return (result);
}

int	ft_is_sep(char to_test, char *str_sep)
{
	int	current;

	current = 0;
	while (str_sep[current])
	{
		if (str_sep[current] == to_test)
			return (1);
		current++;
	}
	return (0);
}

char	*ft_strconcat(char *s1, char *s2)
{
	char	*result;
	int		len_dest;
	int		result_len;
	int		current;

	len_dest = ft_strlength(s1);
	result_len = len_dest + ft_strlength(s2);
	result = malloc(result_len * sizeof(char));
	current = 0;
	while (s1[current])
	{
		result[current] = s1[current];
		current++;
	}
	current = 0;
	while (s2[current])
	{
		result[len_dest + current] = s2[current];
		current++;
	}
	result[result_len] = '\0';
	return (result);
}
