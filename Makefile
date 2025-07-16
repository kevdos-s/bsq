# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kevdos-s <kevdos-s@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 17:34:20 by apisanel          #+#    #+#              #
#    Updated: 2025/07/16 08:49:26 by kevdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = srcs/arguments.c srcs/array_helpers.c srcs/bsq.c srcs/check.c srcs/free_grid.c srcs/grid_helpers.c srcs/main.c srcs/map_creator.c srcs/solve.c srcs/str_utils.c srcs/util.c
OBJS = ${SRCS:.c=.o}
CC = gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror -g

.c.o:
		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}
fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re ${NAME}
