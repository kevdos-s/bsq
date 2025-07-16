/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:51:16 by kevdos-s          #+#    #+#             */
/*   Updated: 2025/07/16 20:09:22 by kevdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_point
{
	int		row;
	int		col;
}			t_point;

typedef struct s_map
{
	int		is_valid;
	int		size_row;
	int		size_col;
	char	empty_char;
	char	obstacle_char;
	char	fill_char;
	int		**dp_map;
	char	**map;
}			t_map;

// util
int			ft_error(char *msg);
void		ft_putstr_error(char *str);
void		ft_putchar(char c);
void		ft_putnb(int nb);
char		*ft_cpy_w_malloc(char *str);
int			ft_strlength(char *str);
void		ft_putstr(char *str);
void		print_line(char *line, int line_size);
void		ft_split_second_part(char *str, char *sep, char **tab,
				int curr_str);
char		**ft_split(char *str, char *separator);
int			ft_is_sep(char to_test, char *str_sep);

# define ERROR_CANNOT_READ_FILE "cannot read file"
# define ERROR_MAP_MSG "map error"

#endif
