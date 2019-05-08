/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 19:25:10 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/08 16:01:47 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

//clang -o fillit fillit.c error.c file_validation.c solver.c  libft/libft.a
void	place_tet(t_tetro *tet, char **map)
{
	int	y;
	int	x;
	int	line;
	int	token;

	line = 0;
	token = 0;
	y = tet->y;
	x = tet->x;
	while (line < tet->height)
	{
		while (tet->tet[line][token] == '.')
		{
			x++;
			token++;
		}
		while ((tet->tet[line][token] != '.') && (token < tet->width))
		{
			map[y][x] = tet->letter;
			x++;
			token++;
		}
		y++;
		line++;
		x = tet->x;
		token = 0;
	}
}
/*
bool check_width_height()
{
	if ((map_size - x - tet->width) < 0)
		return (false);
	if ((map_size - y - tet->height) < 0)
		return (false);
}*/

int		fix_norm_init_var2(short int *token, short int *line, short int *x, t_tetro *tet)
{
	*token = 0;
	*line = 0;
	*x = tet->x;
	return (tet->y);
}

/*
** x = fix_norm_init_var(&token, tet->x, &line, &y);
** y = fix_norm_init_var2(&token, &line, &x, tet);
*/

int		fix_norm_init_var(short int *token, int tet_x, short int *line, short int *y)
{
	*token = 0;
	*line += 1;
	*y += 1;
	return (tet_x);
}

bool	can_place_part2(t_tetro *tet, t_map *map, int check_height, short int success)
{
	short int	line;
	short int	token;
	short int	y;
	short int	x;

	token = 0;
	line = 0;
	x = tet->x;
	y = tet->y;
	y = fix_norm_init_var2(&token, &line, &x, tet);
	while (y < check_height)
	{
		while (tet->tet[line][token] == '.')
			x++ && token++;
		if (map->map[y][x] == '.')
			success++;
		else
			return (false);
		token++;
		while (tet->tet[line][token] != '.' && tet->tet[line][token] != '\0')
		{
			x++;
			if ((map->map[y][x] != '.') || (x == map->size))
				return (false);
			else
				success++;
			token++;
		}
		token = 0;
		line += 1;
		y += 1;
		x = tet->x;
		
	}
	return (success == 4);
}

bool	can_place(t_tetro *tet, t_map *map)
{
	int y;
	int	x;
	int	line;
	int	token;

	y = tet->y;
	x = tet->x;
	line = 0;
	token = 0;
	if ((map->size - x - tet->width) < 0)
		return (false);
	if ((map->size - y - tet->height) < 0)
		return (false);
	return (can_place_part2(tet, map, (tet->height + y), 0));
}

short int	place_figure(t_tetro tet[], t_map *map, bool *found_place)
{
	short int		result;

	place_tet(tet, map->map);
	if ((tet[0].letter - map->tet_amount) == 'A')
		return (SUCCESS);
	result = main_algoritm(&tet[1], map);
	if (result == SMALL_MAP || result == SUCCESS)
		return (result);
	*found_place = false;
	return (result);
}

/*
** Function "end_of_map"
** We reach the last coordinat on the map (map[last - y][last - x]) 
** We tried to place all tetraminos include first tetramino 'A'
** It means we shoud increas the size of map
** If not first tetramino ('A') reach the end of map
** We remove previos tetramino.
** Return (TET_NOT_FIT). Go one step back. Make backtrack.
*/

int8_t	end_of_map(t_tetro tet[], t_map *map)
{
	if (tet[0].letter == 'A')
		return (SMALL_MAP);
	del_tet(map->map, tet[-1].letter, '.', map->size);
	return (TET_NOT_FIT);
}

/**
**	print_map(map, map_size);ft_putchar('\n');
**/

int8_t		main_algoritm(t_tetro tet[], t_map *map)
{
	bool	found_place;
	int8_t	result;

	while (found_place == false)
	{
		map->i += 1;
		(tet[0].first_try) ? (tet[0].first_try = false) : (tet[0].x += 1);
		if (map->i >= N)
			return (-1);
		if (tet[0].x == map->size)
		{
			if (tet[0].y == (map->size - 1))
				return (end_of_map(tet, map));
			tet[0].x = 0;
			tet[0].y += 1;
		}
		found_place = can_place(tet, map);
		if (found_place)
		{
			result = place_figure(tet, map, &found_place);
			if (result == SMALL_MAP || result == SUCCESS)
				return (result);
		}
	}
	return (SUCCESS);
}
