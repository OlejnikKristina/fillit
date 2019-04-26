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

/*
**clang -o fillit fillit.c error.c file_validation.c libft/libft.a
*/

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
** Function measures height of every tetramino.
** And put it in struct's variable y 
*/

void	set_tet_height(t_tetro *tet[], char tet_arr[][4][6], short int size)
{
	int8_t	y;
	int8_t	x;

	y = 0;
	x = 0;
	tet[size]->y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tet_arr[0][y][x] == '#')
			{
				tet[size]->y += 1;
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

void	set_tet_width(t_tetro *tet[], char tet_arr[][4][6], short int size)
{
	int8_t	y;
	int8_t	x;

	y = 0;
	x = 0;
	tet[size]->x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tet_arr[0][y][x] == '#')
			{
				tet[size]->x += 1;
				break ;
			}
			y++;
		}
		x++;
	}
//	printf("size %d\n", size);
//	printf("tet[%d]->y = %d\n", size, tet[size]->y);
//	printf("tet[%d]->x = %d\n", size, tet[size]->x);
	if (size)
		set_tet_width(tet, &tet_arr[-1], size - 1);
}

void	cut_tet(t_tetro *tet[], char tet_arr[][4][6], short int size)
{
//	tet_mem_aloc();
	int	i;

	i = 0;
	tet[size]->tet = (char **)ft_memalloc(sizeof(char *) * tet[size]->y);
	while (i < tet[size]->x)
	{
		tet[size]->tet[i] = (char *)ft_strnew(sizeof(char) * tet[size]->x);
		tet[size]->tet[i] = "Hello this simply works!";
		printf("tet[%d]->tet[i] = %s\n", size, tet[size]->tet[i]);
		i++;
	}
//	printf("size: %d", size);
	if (size)
		cut_tet(tet, &tet_arr[-1], size - 1);
}


/*
**
** Function "pick_data" gather info from 3 dimensional array. 
** Which store entire valid map/file. (Uses automatic mem).
** And put info about tetrominos in array of pointers to struts.
** Every struct has info about: 
** Tetrominos width (tet[0]->x), heghit (tet[0]->y)
**
*/

int8_t	pick_data(char tet_arr[][4][6], short int size)
{
	t_tetro	*tet[size];
	uint8_t	i;

	i = 0;
	if (mem_alocation(tet, size) == -1)
			return (-1);
	tet[i]->letter = 'A';
	set_tet_height(tet, &tet_arr[size - 1], size - 1);
	set_tet_width(tet, &tet_arr[size - 1], size - 1);
	cut_tet(tet, &tet_arr[size - 1], size - 1);
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
