/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:40:13 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/15 21:04:52 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"
#include "global.h"
#include <stdlib.h>
#include <unistd.h>

// int	main(int argc, char **argv)
// {
// 	(void)argv;
// 	if (argc == 1)
// 	{
// 		// TODO: Handle input from stdin
// 	}
// 	else
// 	{
// 		int i;
// 		t_map *map_ctx;

// 		i = 1;
// 		while (i < argc)
// 		{
// 			map_ctx = get_map_from_path(argv[i]);
// 			if (map_ctx == NULL)
// 			{
// 				write(2, "Error reading map\n", 18);
// 				return (1);
// 			}
// 		}

// 		return (0);
// 	}

// 	return (0);
// }