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

int8_t	struct_mem_aloc(t_tetro *tet[], uint8_t size)
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

void	set_tet_height(t_tetro *tet[], char tet_arr[][4][6], uint8_t size)
{
	int8_t	y;
	int8_t	x;

	y = 0;
	x = 0;
	tet[size]->height = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tet_arr[0][y][x] == '#')
			{
				tet[size]->height += 1;
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

void	set_tet_width(t_tetro *tet[], char tet_arr[][4][6], uint8_t size)
{
	int8_t	y;
	int8_t	x;

	y = 0;
	x = 0;
	tet[size]->width = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tet_arr[0][y][x] == '#')
			{
				tet[size]->width += 1;
				break ;
			}
			y++;
		}
		x++;
	}
	if (size)
		set_tet_width(tet, &tet_arr[-1], size - 1);
}

void	find_coord(char tet_arr[][4][6], int *coord_x, int *coord_y)
{
	int8_t	x;
	int8_t	y;

	*coord_x = -1;
	y = 0;
	while ((y < 4))
	{
		if (ft_strchr(&tet_arr[0][y][0], '#'))
		{
			*coord_y = y;
			break ;
		}
		y++;
	}
	x = 0;
	while ((x < 4) && (*coord_x == -1))
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

void	cut_tet(t_tetro *tet[], char tet_arr[][4][6], uint8_t size, char letter)
{
	int	coord_x;
	int	coord_y;
	int8_t	i;
	int8_t	index;

	index = 0;
 /*	printf("%s", tet_arr[0][0]);
	printf("%s", tet_arr[0][1]);
	printf("%s", tet_arr[0][2]);
	printf("%s\n", tet_arr[0][3]);*/
	find_coord(tet_arr, &coord_x, &coord_y);
	i = tet[0]->height;
	while (index < tet[0]->height)
	{
		tet[0]->tet[index] = ft_strsub(tet_arr[0][coord_y], coord_x, tet[0]->width);
		coord_y++;
		tet[0]->tet[index][tet[0]->width] = '\0';
		//printf("tet[0]->height %d\n", tet[0]->height);
		chr_replace(tet[0]->tet[index], '#', letter, 4);
		//printf("\"%s\"\n", tet[0]->tet[index]);
		i--;
		index++;
	}
//	printf("--------------------------\n");
	if (size)
		cut_tet(&tet[-1], &tet_arr[-1], size - 1, letter - 1);
}

void	tet_mem_aloc(t_tetro *tet[], char tet_arr[][4][6], uint8_t size)
{
	int8_t	line;

	line = 0;
	tet[size]->tet = (char **)ft_memalloc(sizeof(char *) * tet[size]->height);
	while (line < tet[size]->width)
	{
		//tet[size]->tet[line] = (char *)ft_strnew(sizeof(char) * tet[size]->x);
		//printf("tet[%d]->tet[i] = %s\n", size, tet[size]->tet[line]);
		line++;
	}
	if (size)
		tet_mem_aloc(tet, &tet_arr[-1], size - 1);
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

int8_t	store_data(char tet_arr[][4][6], uint8_t size)
{
	t_tetro	*tet[size];
	uint8_t	i;

	i = 0;
	if (struct_mem_aloc(tet, size) == -1)
			return (-1);
	size--;
	set_tet_height(tet, &tet_arr[size], size);
	set_tet_width(tet, &tet_arr[size], size);
	tet_mem_aloc(tet, &tet_arr[size], size);
	cut_tet(&tet[size], &tet_arr[size], size, 'A' + size);
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
