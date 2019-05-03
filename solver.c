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
				return (false);
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
		return (true);
	return (false);
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


bool		solver(t_tetro *tet[], char **map, int map_size, uint8_t tet_amount)
{
	bool found_place;
	int	res;

	printf("tet amount: %hhu\n", tet_amount);
	if (tet[0]->first_try)
	{
		//printf("Check before increament!\n");
		tet[0]->x = 0;
		tet[0]->y = 0;
		tet[0]->first_try = false;
		found_place = can_place(tet[0], map, map_size);
		//place_tet(tet[0], map);
		//printf("D tet block x=%d y=%d, found_place %d\n", tet[0]->x, tet[0]->y, found_place);
	}
	//printf("LETTER: %c x=%d y=%d\n", tet[0]->letter, tet[0]->x, tet[0]->y);
	while (found_place == false)
	{
		tet[0]->x += 1;
		if (tet[0]->x == map_size)
		{
			if (tet[0]->y == (map_size - 1))
			{
				if (tet[0]->letter == 'A')
				{
					printf("Make map really bigger!!!\n");
					return (false);
				}
				res = find_C(tet[-1], map, map_size);
				//printf("FIND pos: x=%d y=%d\n", tet[-1]->x, tet[-1]->y);
				del_tet(map, tet[-1]->letter, '.', map_size);
				print_map(map, map_size);ft_putchar('\n');
				if (solver(&tet[-1], map, map_size, tet_amount) == false)
					return (false);
			}
			tet[0]->x = 0;
			tet[0]->y += 1;
		}
		found_place = can_place(tet[0], map, map_size);
	}
	place_tet(tet[0], map);
	print_map(map, map_size);ft_putchar('\n');
	if ((tet[0]->letter - tet_amount) == 'A')
		printf("Segfault?? %c\n", ((tet[0]->letter - tet_amount) != 'A'));
	if ((tet[0]->letter - tet_amount) != 'A')
	{
		//printf("Segfault??\n");
		tet[1]->x = 0;
		tet[1]->y = 0;
		if (solver(&tet[1], map, map_size, tet_amount)== false)
			return (false);
	}
	return (true);
}







		//print_map(map, map_size);
		//printf("null (?) %s\n", tet[1]->tet[0]);
	/*	if(tet[0]->letter == 'D')
		{
			place_tet(tet[0], map);
			print_map(map, map_size);
		}*/
		//return (0);

/*

#...
#...
#...
#...

....
....
##..
##..

###.
#...
....
....

.#..
.#..
##..
....







success = -1;
	tet[1]->x = 3;
	tet[1]->y = 0;
	res = can_place(tet[1], map, map_size);
	printf("x=%d y=%d res: %d\n", tet[1]->x, tet[1]->y, res);
	place_tet(tet[1], map);
	print_map(map, map_size);
	return (-1);

....
##..
.#..
.#..

....
####
....
....

#...
###.
....
....

....
##..
.##.
....

*/