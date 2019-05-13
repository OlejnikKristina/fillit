/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_algoritm.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 19:25:10 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/13 19:52:31 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** clang -o fillit serve_data.c file_validation.c main_algoritm.c
** auxiliary_funcs.c auxiliary_funcs2.c main.c print_map.c libft/libft.a -g
*/

int8_t	place(t_tetro tet, t_map *map, short int line, short int token)
{
	int x;
	int y;

	y = tet.y;
	x = tet.x;
	while (line < tet.height)
	{
		while (tet.tet[line][token] == '.')
		{
			x++;
			token++;
		}
		while ((tet.tet[line][token] != '.') && (token < tet.width))
		{
			map->map[y][x] = tet.letter;
			x++;
			token++;
		}
		y++;
		line++;
		x = tet.x;
		token = 0;
	}
	return (1);
}

bool	can_place(t_tetro *tet, t_map *map, int start_x, int start_y)
{
	int x;
	int y;

	if (map->size < start_x + tet->width)
		return (false);
	if (map->size < start_y + tet->height)
		return (false);
	y = 0;
	while (y < tet->height)
	{
		x = 0;
		while (x < tet->width)
		{
			if (tet->tet[y][x] != '.' &&
			map->map[start_y + y][start_x + x] != '.')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

int8_t	end_of_map(t_tetro tet[], t_map *map)
{
	if (tet[0].letter == 'A')
		return (SMALL_MAP);
	else
		del_tet(map->map, tet[-1].letter, '.', map->size);
	return (TET_NOT_FIT);
}

void	set_value(t_tetro *tet)
{
	tet[1].x = 0;
	tet[1].y = 0;
	tet[1].first_try = true;
}

/*
** print_map(map, map_size);
*/

int8_t	solver(t_tetro tet[], t_map *map, int result)
{
	while (1)
	{
		map->i += 1;
		(tet[0].first_try) ? (tet->first_try = false) : (tet->x += 1);
		if (map->i >= N)
			return (-1);
		if (tet[0].x == map->size)
		{
			if (tet[0].y == (map->size - 1))
				return (end_of_map(tet, map));
			tet[0].x = 0;
			tet[0].y += 1;
		}
		if (can_place(tet, map, tet->x, tet->y))
		{
			if (place(tet[0], map, 0, 0) && (tet[0].letter - map->amnt) == 'A')
				return (SUCCESS);
			set_value(&tet[0]);
			result = solver(&tet[1], map, 0);
			if (result == SMALL_MAP || result == SUCCESS)
				return (result);
		}
	}
	return (SUCCESS);
}
