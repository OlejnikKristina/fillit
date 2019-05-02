/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algoritm.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 19:25:10 by krioliin      #+#    #+#                 */
/*   Updated: 2019/04/25 19:25:12 by krioliin      ########   odam.nl         */
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

int8_t	check_tet(t_tetro *tet, char **map, int map_size)
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
	while ((y < check_height) && (y < map_size))
	{
		while (tet->tet[line][token] == '.')
		{
			x++;
			token++;
		}
		if (map[y][x] == '.')
			success++;
		token++;
		while ((tet->tet[line][token] != '.') && (tet->tet[line][token] != '\0'))
		{
			x++;
			if (x == map_size)
				return (-1);
			if (map[y][x] == '.')
				success++;
			token++;
			if ((tet->tet[line][token] == '\0') || (tet->tet[line][token] == '.'))
				break ;
		}
		token = 0;
		x = tet->x;
		line++;
		y++;
	}
	if (success == 4)
		return (0);
	return (-1);
}

bool	find_C(t_tetro *tet, char **map, int map_size)
{
	int8_t	x;
	int8_t	y;

	y = 0;
	tet->x = -1;
	while ((y < map_size))
	{
		if (ft_strchr(map[y], tet->letter))
		{
			tet->y = y;
			break ;
		}
		y++;
	}
	x = 0;
	while ((x < map_size) && (tet->x == -1))
	{
		y = 0;
		while (y < map_size)
		{
			if (map[y][x] == tet->letter)
			{
				tet->x = x;
				break ;
			}
			y++;
		}
		x++;
	}
	return (true);
}


int		solver(t_tetro *tet[], char **map, int map_size)
{
	int success;
	int	res;

	printf("map_size %d\n", map_size);
	if ((tet[0]->x == 0) && (tet[0]->y == 0))
		success = check_tet(tet[0], map, map_size);
	while (success == -1)
	{
		tet[0]->x += 1;
		if (tet[0]->x == map_size)
		{
			if (tet[0]->y == (map_size - 1))
			{
				res = find_C(tet[-1], map, map_size);
				del_tet(map, tet[-1]->letter, '.', map_size);
			//	solver(&tet[-1], map, map_size);
			//	++tet[-1]->x;
			/*
				if (tet[-1]->x == map_size)
				{
					tet[-1]->x = 0;
					++tet[-1]->y;
					if (tet[-1]->y == (map_size - 1))
						{return (-1);}
				}*/
				printf("x=%d y=%d res: %d\n", tet[-1]->x, tet[-1]->y, res);
			//	solver(&tet[-1], map, map_size);
				printf("Figures don\'t fit!\n");
				return (-1);
				print_map(map, map_size);

				printf("Make map really bigger %c|%c\n", tet[0]->letter, tet[-1]->letter+ - map_size);
			//	solver(&tet[0], map, map_size);
				return (-1);
			}
			tet[0]->x = 0;
			tet[0]->y += 1;
		}
		success = check_tet(tet[0], map, map_size);
	}
	place_tet(tet[0], map);
	print_map(map, map_size);
	if (tet[1]->tet[0] != NULL)
		solver(&tet[1], map, map_size);
	return (0);
}


/*

success = -1;
	tet[1]->x = 3;
	tet[1]->y = 0;
	res = check_tet(tet[1], map, map_size);
	printf("x=%d y=%d res: %d\n", tet[1]->x, tet[1]->y, res);
	place_tet(tet[1], map);
	print_map(map, map_size);
	return (-1);
*/