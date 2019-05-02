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
# include <stdbool.h>
#include <stdio.h>
# define PROTECT(x) if (!(x)) return (NULL);

typedef struct		s_tetro
{
	int				width;
	int				height;
	char			**tet;
	char			letter;
	int				x;
	int				y;
	int				shape;
}					t_tetro;

typedef	struct		s_map 
{
	char			**map;
	int				map_size;

}					t_map;


uint8_t				error_msg(int error);
int					open_file(const char *file);
int8_t				check_file(char *file);
int8_t				check_map(const int fd, int8_t *tet_num, int line, int last_line);
int8_t				check_shape(const int fd, int8_t tet_amount);
int8_t				store_data(char tet_arr[][4][6], uint8_t size);
void				chr_replace(char *str, int target, int replace, int32_t len);
void				del_tet(char **map, int target, int replace, int map_size);
int					solver(t_tetro *tet[], char **map, int map_size);
int					kr_sqrt(int nb);

void	print_map(char **map, int map_size);



#endif
