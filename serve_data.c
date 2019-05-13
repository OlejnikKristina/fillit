/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   serve_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/14 20:28:10 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/13 19:46:41 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <inttypes.h>

/*
** Function measures height of every tetramino.
** And put it in struct's variable y
** clang -o fillit fillit.c error.c
** file_validation.c solver.c auxiliary_functions.c main.c libft/libft.a
*/

void	set_tet_height(t_tetro tet[], char tet_arr[][4][6], uint8_t size)
{
	int8_t	y;
	int8_t	x;

	y = 0;
	x = 0;
	tet[size].height = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tet_arr[0][y][x] == '#')
			{
				tet[size].height += 1;
				break ;
			}
			x++;
		}
		y++;
	}
	if (size)
		set_tet_height(tet, &tet_arr[-1], size - 1);
}

/*
** Function measures width of every tetramino.
** And put it in struct's variable x
*/

void	set_tet_width(t_tetro tet[], char tet_arr[][4][6], uint8_t size)
{
	int8_t	y;
	int8_t	x;

	y = 0;
	x = 0;
	tet[size].width = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tet_arr[0][y][x] == '#')
			{
				tet[size].width += 1;
				break ;
			}
			y++;
		}
		x++;
	}
	if (size)
		set_tet_width(tet, &tet_arr[-1], size - 1);
}

/*
** Function 'find_coord' find first occurence of '#'
** And store its coordinat into '*coord_x' and '*coord_y'
*/

void	find_coord(char tet_arr[][4][6], int *coord_x, int *coord_y, int8_t y)
{
	int8_t	x;

	*coord_x = -1;
	y = 0;
	while (y < 4)
	{
		if (ft_strchr(&tet_arr[0][y][0], '#'))
		{
			*coord_y = y;
			break ;
		}
		y++;
	}
	x = 0;
	while (x < 4 && *coord_x == -1)
	{
		y = 0;
		while (y < 4)
		{
			if (tet_arr[0][y][x] == '#')
			{
				*coord_x = x;
				break ;
			}
			y++;
		}
		x++;
	}
}

/*
** Function 'cut_tet' cut block which represent a tetramino (figure)
** to the minimum unit which still be able to represent a shape of figure
** For instanse:
** not-cut:		cut:	Every not-cut block store in one element
**	.###		###		tet_arr[num_of_block][num_of_line][num_of_charater]
**	.#..		#..
**	....				Every cut block lockets in sytruct 'tet'
**	....				store as (char **) which also named 'tet'
**						tet[num_of_block].tet[num_of_line][num_of_charater]
*/

void	cut_tet(t_tetro tet[], char tet_arr[][4][6], uint8_t size, char letter)
{
	int8_t	i;
	int8_t	index;
	int		x;
	int		y;

	index = 0;
	find_coord(tet_arr, &x, &y, 0);
	i = tet[0].height;
	tet[0].letter = letter;
	tet[0].tet = (char **)ft_memalloc(sizeof(char *) * tet[0].height);
	while (index < tet[0].height)
	{
		tet[0].tet[index] = ft_strsub(tet_arr[0][y], x, tet[0].width);
		y++;
		tet[0].tet[index][tet[0].width] = '\0';
		tet[0].x = 0;
		tet[0].y = 0;
		tet[0].first_try = true;
		chr_replace(tet[0].tet[index], '#', letter, 4);
		i--;
		index++;
	}
	if (size)
		cut_tet(&tet[-1], &tet_arr[-1], size - 1, letter - 1);
}

/*
** Varieble size = amount of tetromino
** Function "pick_data" gather info from 3 dimensional array.
** Which store entire valid map/file. (Uses automatic mem).
** And put info about tetrominos in array of pointers to struts.
** Every struct has info about:
** Tetrominos width (tet[0]->x), heghit (tet[0]->y)
*/

void	serve_data(char tet_arr[][4][6], uint8_t tet_amount)
{
	t_tetro	tet[tet_amount];
	t_map	map;

	map.size = kr_sqrt((tet_amount) * 4);
	tet_amount--;
	map.amnt = tet_amount;
	set_tet_height(tet, &tet_arr[tet_amount], tet_amount);
	set_tet_width(tet, &tet_arr[tet_amount], tet_amount);
	cut_tet(&tet[tet_amount], &tet_arr[map.amnt], tet_amount, 'A' + tet_amount);
	map.i = 0;
	map.map = map_mem_aloc(map.map, map.size);
	while (solver(tet, &map, 0) == SMALL_MAP)
	{
		del_arr(map.map, map.size);
		turn_back_time(&tet[tet_amount], tet_amount);
		map.size += 1;
		map.i = 0;
		map.map = map_mem_aloc(map.map, map.size);
	}
	print_tet_amount(tet_amount);
	print_map(map.map, map.size);
	clean_struct(tet, tet_amount);
	del_arr(map.map, map.size);
}
