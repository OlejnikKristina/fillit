/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/14 20:28:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/13 19:50:28 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include "colorful_fillit.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <inttypes.h>
# include <stdbool.h>

# define TET_NOT_FIT -2
# define SMALL_MAP -1
# define SUCCESS 1

typedef struct	s_tetro
{
	int			width;
	int			height;
	char		**tet;
	char		letter;
	int			x;
	int			y;
	bool		first_try;
}				t_tetro;

typedef	struct	s_map
{
	char		**map;
	int			size;
	int			i;
	uint8_t		amnt;

}				t_map;

int8_t			check_file(char *file);
uint8_t			error_msg(int error);
int				open_file(const char *file);
int8_t			check_map(const int fd, int8_t *tet_num,
				int line, int last_line);
int8_t			check_shape(const int fd, int8_t tet_amount, int8_t i);
void			serve_data(char tet_arr[][4][6], uint8_t size);
char			**map_mem_aloc(char **map, int map_size);
void			chr_replace(char *str, int target, int replace, int32_t len);
void			del_tet(char **map, int target, int replace, int map_size);
int8_t			solver(t_tetro tet[], t_map *map, int result);
int				kr_sqrt(int nb);
void			turn_back_time(t_tetro tet[], uint8_t size);
void			del_arr(char **str_arr, int8_t size);
void			clean_struct(t_tetro tet[], uint8_t size);
void			print_map(char **map, int map_size);
void			fix_norm(int8_t *tet_num, int *last_line, int *line);
void			plusone(t_tetro *tet);
void			setfalse(t_tetro *tet);
int				equal_x(int *coord_x, int8_t x);
void			set_val(int *line, int *last_line);
void			print_tet_amount(uint8_t tet_amount);

#endif
