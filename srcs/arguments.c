/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:46:14 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/15 20:12:41 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	**get_map_from_std_input(void)
{
	char	ch;
	char	*map;
	int		i;

	map = NULL;
	i = 0;
	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		map[i] = ch;
		i++;
	}
	printf("%s", map);
	return (NULL);
}

t_map	*get_map_from_path(char *path)
{
	int		reading;
	int		file;
	char	buffer;
	t_map	*map_ctx;

	file = open(path, 0);
	if (file == -1)
		return (0);
	while ((reading = read(file, &buffer, 1)))
	{
		if (reading == -1)
			return (0);
		write(1, &buffer, 1);
	}
	close(file);
	return (NULL);
}
