/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/14 20:28:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/15 21:15:45 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <inttypes.h>
# include <errno.h>
#include <stdio.h>
# define PROTECT(x) if (!(x)) return (NULL);

typedef struct		s_tetro
{
	int				x;
	int				y;
	char			**tet;
	int				shape;
	char			letter;
}					t_tetro;


typedef struct		s_tetra
{
	short int	x[4];
	short int	y[4];
	char			letter;
	struct s_tetra	*next;
}					t_tetra;

typedef struct		s_tet
{
	uint8_t			shape;
}					t_tet;

struct				s_shape
{
	uint8_t			y[4];
	uint8_t			x[4];
	uint8_t			index;
}					shape[19];

uint8_t				error(int error);
const int			open_file(const char *file);
int8_t				check_file(char *file);
int8_t				check_map(const int fd, int8_t *tet_num, int line, int last_line);
int8_t				check_shape(const int fd, short int tet_amount);
int8_t				pick_data(char tet_arr[][4][6], short int size);

#endif
