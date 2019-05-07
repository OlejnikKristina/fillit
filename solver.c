/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 19:25:10 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/07 15:10:20 by krioliin      ########   odam.nl         */
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

bool	can_place(t_tetro *tet, char **map, int map_size)
{
	int y;
	int	x;
	int	line;
	int	token;
	int success;
	int check_height;

	y = tet->y;
	x = tet->x;
	line = 0;
	token = 0;
	success = 0;
	check_height = tet->height + y;
	if ((map_size - x - tet->width) < 0)
		return (false);
	if ((map_size - y - tet->height) < 0)
		return (false);
	while (y < check_height)
	{
		while (tet->tet[line][token] == '.')
		{
			x++;
			token++;
		}
		if (map[y][x] == '.')
			success++;
		else
			return (false);
		token++;
		while ((tet->tet[line][token] != '.') && (tet->tet[line][token] != '\0'))
		{
			x++;
			if (x == map_size)
				return (false);
			if (map[y][x] == '.')
				success++;
			else
				return (false);
			token++;
		}
		token = 0;
		x = tet->x;
		line++;
		y++;
	}
	return (success == 4);
}

int8_t		solver(t_tetro *tet[], char **map, int map_size, uint8_t tet_amount, int *i)
{
	bool	found_place = false;
	int		result;

	while (found_place == false)
	{
		*i += 1;
		if (tet[0]->first_try)
			tet[0]->first_try = false;
		else
			tet[0]->x += 1;
		if (*i >= N)
			return (-1);
		if (tet[0]->x == map_size)
		{
			if (tet[0]->y == (map_size - 1))
			{
				if (tet[0]->letter == 'A')
					return (SMALL_MAP);
				del_tet(map, tet[-1]->letter, '.', map_size);
			//	print_map(map, map_size);ft_putchar('\n');
				return (TET_NOT_FIT);
			}
			tet[0]->x = 0;
			tet[0]->y += 1;
		}
		found_place = can_place(tet[0], map, map_size);
		if (found_place)
		{
			place_tet(tet[0], map);
		//	print_map(map, map_size);ft_putchar('\n');
			if ((tet[0]->letter - tet_amount) == 'A')
				return (SUCCESS);
			tet[1]->x = 0;
			tet[1]->y = 0;
			result = solver(&tet[1], map, map_size, tet_amount, i);
			if (result == SMALL_MAP || result == SUCCESS)
				return (result);
			found_place = false;
		}
	}
	return (SUCCESS);
}
