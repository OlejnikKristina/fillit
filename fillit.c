/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/14 20:28:10 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/15 21:12:54 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int8_t	mem_alocation(t_tetro *tet[], short int size)
{
	int8_t	i;

	i = 0;
	while (i < size)
	{
		tet[i] = (t_tetro *)malloc(sizeof(t_tetro));
		if (tet[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}
/*
**if (--size)
**		set_tet_size(&tet[size], tet_arr, size);
*/
int8_t	set_tet_size(t_tetro *tet[], char tet_arr[][4][6], short int size)
{
	int8_t	i;
	int		y;
	int		x;

	i = 0;
	y = 0;
	x = 0;
	printf("size %d\n", size);
	while (i <= size)
	{
		tet[i]->y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (tet_arr[i][y][x] == '#')
				{
					tet[i]->y += 1;
					break ;
				}
				x++;
			}
			y++;
		}
		printf("tet[%d]->y = %d\n", i, tet[i]->y);
		i++;
		y = 0;
	}
	return (0);
}

int8_t	algoritm(char tet_arr[][4][6], short int size)
{
	t_tetro	*tet[size];
	uint8_t	i;

	i = 0;
	if (mem_alocation(tet, size) == -1)
			return (-1);
	tet[i]->letter = 'A';
	printf("size1 %d\n", size);
	set_tet_size(tet, tet_arr, size - 1);
	printf(("letter: %c\n"), tet[2]->letter);
	return (0);
}

int		main(int argc, char **argv)
{
	if ((argc != 2) && error(4))
		return (0);
	if ((check_file(argv[1]) == -1))
		return (0);
	printf("Success\n");
	return (0);
}
