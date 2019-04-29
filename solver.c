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
// 3 tetro =  12 char = sqrt(12) +-= 4;
/*
....
....
....
....
*/

void	place_tet(t_tetro *tet, char **map, int map_size, int coord[2], char letter)
{
	int	y;
	int	x;
	int	line;
	int token;
	
	line = 0;
	token = 0;
	y = coord[0];
	x = coord[1];
	while (line < tet->height)
	{
		while (tet->tet[line][token] == '.')
		{
			x++;
			token++;
		}
		while ((tet->tet[line][token] != '.') && (token < tet->width))
		{
			map[y][x] = letter;
			x++;
			token++;
		}
		y++;
		line++;
		x = coord[1];
		token = 0;
	}
}

int8_t	check_tet(t_tetro *tet, char **map, int map_size, int coord[2])
{
	int y;
	int	x;
	int	line;
	int	token;
	int success;

	y = coord[0];
	x = coord[1];
	line = 0;
	token = 0;
	success = 0;

	while ((y < map_size) && (y < tet->height))
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
		x = coord[1];
		line++;
		y++;
	}
	if (success == 4)
		return (0);
	return (-1);
}

int		solver(t_tetro *tet[], char **map, int map_size)
{
	int success;
	int	coord[2];
	int num;
	char letter;

	coord[0] = 0;//y
	coord[1] = 0;//x
	num = 0;
	letter = 'A';
	printf("map_size %d\n", map_size);

	while (num < 3)
	{
		while (success == -1)
		{
			coord[1] += 1;
			if (coord[1] == map_size)
			{
				coord[0] += 1;
				coord[1] = 0;
			}
			success = check_tet(tet[num], map, map_size, coord);
		}
		place_tet(tet[num], map, map_size, coord, letter);
		letter++;
		num++;
	}

	printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	printf("%s\n", map[3]);
	return (0);
}

/*

while (success == -1)
	{
		coord[1] += 1;
		if (coord[1] == map_size)
		{
			coord[0] += 1;
			coord[1] = 0;
		}
		success = check_tet(tet[3], map, map_size, coord);
	}

	if (success != -1)
		place_tet(tet[0], map, map_size, coord, 'A');
	printf("result: %d\n", success);

	coord[1] += 1;
	success = check_tet(tet[3], map, map_size, coord);
	if (success != -1)
		place_tet(tet[3], map, map_size, coord, 'B');



&& (tet->tet[line][token] != '\0')
	while (i <= map_size)
	{
		if (map[i][y] == '.')
		{
			while(y < tet->height)
			{
				if (map[i][y] != '.')
					break ;
				y++;
			}
			while()
			{
				
			}
			
			
		} 
	}


	while (tet->tet[line][token] == '.')
			{
				x++;
				if (x == (map_size - 1))
					return (-1);
				token++;
			}

	static char letter = 'A';

	ft_memset(test_map[0], '.', map_size);
	ft_memset(test_map[1], '.', map_size);
	ft_memset(test_map[2], '.', map_size);
	ft_memset(test_map[3], '.', map_size);
	test_map[0][map_size] = '\0';
	test_map[1][map_size] = '\0';
	test_map[2][map_size] = '\0';
	test_map[3][map_size] = '\0';

//	success = check_tet(tet[2], map, map_size, coord);
//	printf("result: %d\n", success);*/	
/*	success = check_tet(tet[6], map, map_size, coord);
	success = check_tet(tet[7], map, map_size, coord);
	success = check_tet(tet[8], map, map_size, coord);
	success = check_tet(tet[9], map, map_size, coord);*/


/*
DAAAA
DBBC
DBBC
D.CC
.....

DBB
DBB
D
D

.#..
.#..
##..
....

....
##..
##..
....

....
.##.
##..
....

...#
...#
...#
...#

....
....
....
####

#...
###.
....
....

....
....
...#
.###

....
....
..#.
.###
*/
