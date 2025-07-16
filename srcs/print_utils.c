/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisanel <apisanel@students.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:30:26 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 21:18:14 by apisanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_utils.h"

void	ft_putstr_error(char *str)
{
	int	current;

	current = 0;
	while (str[current])
	{
		write(2, &str[current], 1);
		current++;
	}
	write(2, "\n", 1);
}

void	ft_putstr(char *str)
{
	int	current;

	current = 0;
	while (str[current])
	{
		write(1, &str[current], 1);
		current++;
	}
}

void	print_line(char *line, int line_size)
{
	write(1, line, line_size);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnb(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -(nb);
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_putnb(nb / 10);
		ft_putnb(nb % 10);
	}
}
