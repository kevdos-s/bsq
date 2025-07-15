/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:30:26 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/15 20:19:20 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_error(char *msg)
{
	ft_putstr_error(msg);
	ft_putchar('\n');
	return (0);
}

void ft_putstr_error(char *str)
{
	int current;

	current = 0;
	while (str[current])
	{
		write(2, str[current], 1);
	}
}
int ft_strlength(char *str)
{
	int current;

	current = 0;

	while (str[current])
	{
		current++;
	}
	return (current);
}
void ft_putchar(char c)
{
	write(1, &c, 1);
}

char *ft_cpy_w_malloc(char *str)
{
	int current;
	int len_str;
	char *result;

	len_str = ft_strlength(str);
	result = malloc(len_str * sizeof(char));
	current = 0;
	while (str[current])
	{
		result[current] = str[current];
		current++;
	}
	result[current] = '\0';

	return (result);

}

char *ft_strdup(char *dest, char *src)
{
	int current;
	int len_dest;
	int result_len;
	char *result;

	len_dest = ft_strlength(dest);
	result_len = len_dest + ft_strlength(src);
	result = malloc(result_len * sizeof(char));
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

}

char	**ft_split(char *str, char separator)
{
	char	**tab;
	int		size_tab;

	size_tab = ft_count_sep(str, separator);
	tab = (char **)malloc(size_tab * sizeof(char *));

	ft_split_second_part(str, separator, tab, 0);

	return (tab);
}

void ft_split_second_part(char *str, char sep, char **tab, int curr_str)
{
	int curr_tab_str;
	int l_start_pos;
	int l_current_index_tab;

	curr_tab_str = 0;
	l_start_pos = 0;
	l_current_index_tab = 0;
	while (str[curr_str] != '\0')
	{
		if (str[curr_str] == sep || str[curr_str + 1] == '\0')
		{
			if (str[curr_str + 1] == '\0')
				curr_str++;
			tab[l_current_index_tab] = malloc((curr_str - l_start_pos + 1) * sizeof(char));
			while (l_start_pos < curr_str)
			{
				tab[l_current_index_tab][curr_tab_str] = str[l_start_pos];
				curr_tab_str++;
				l_start_pos ++;
			}
			tab[l_current_index_tab][curr_tab_str] = '\0';
			l_start_pos++;
			l_current_index_tab++;
			curr_tab_str = 0;
		}
		curr_str++;
	}
}
int ft_count_sep(char *str, char sep)
{
	int i;
	int result;

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
