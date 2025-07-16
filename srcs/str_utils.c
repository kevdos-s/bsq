/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:55:25 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 09:58:09 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlength(char *str)
{
	int	current;

	current = 0;
	while (str[current])
	{
		current++;
	}
	return (current);
}

char	*ft_strdup(char *dest, char *src)
{
	int		current;
	int		len_dest;
	int		result_len;
	char	*result;

	len_dest = ft_strlength(dest);
	result_len = len_dest + ft_strlength(src);
	result = malloc(result_len * sizeof(char));
	current = 0;
	while (dest[current])
	{
		result[current] = dest[current];
		current++;
	}
	current = 0;
	while (src[current])
	{
		result[len_dest] = src[current];
		current++;
		len_dest++;
	}
	result[current] = '\0';
	return (result);
}

int	ft_count_sep(char *str, char sep)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == sep || str[i + 1] == '\0')
		{
			result++;
		}
		i++;
	}
	return (result);
}
int ft_atoi(char *str)
{
	int result;
	int current;

	result = 0;
	current = 0;
	while (str[current] >= '0' && str[current] <= '9')
	{
		result = (result * 10) + (str[current] - 48);
		current++;
	}
	return (result);
}
