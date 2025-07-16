/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:17:09 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/16 21:17:10 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	**ft_split(char *str, char *separator)
{
	char	**tab;
	int		size_tab;

	size_tab = ft_count_multi_sep(str, separator);
	tab = (char **)malloc(size_tab * sizeof(char *));
	ft_split_second_part(str, separator, tab, 0);
	return (tab);
}

void	ft_split_second_part(char *str, char *sep, char **tab, int curr_str)
{
	int	curr_tab_str;
	int	l_start_pos;
	int	l_current_index_tab;

	curr_tab_str = 0;
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
			while (l_start_pos < curr_str)
			{
				tab[l_current_index_tab][curr_tab_str] = str[l_start_pos];
				curr_tab_str++;
				l_start_pos++;
			}
			tab[l_current_index_tab][curr_tab_str] = '\0';
			if (str[curr_str] == '\\' && str[curr_str + 1] == 'n')
			{
				l_start_pos++;
				curr_str++;
			}
			l_start_pos++;
			l_current_index_tab++;
			curr_tab_str = 0;
		}
		curr_str++;
	}
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
	int current;
	int len_dest;
	int result_len;
	char *result;

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