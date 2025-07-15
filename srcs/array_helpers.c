/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:14:56 by apisanel          #+#    #+#             */
/*   Updated: 2025/07/15 17:16:00 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int *args, int size)
{
	int i;
	int min;

	i = 1;
	min = args[0];
	while (i < size)
	{
		if (args[i] < min)
			min = args[i];
		i++;
	}
	return (min);
}