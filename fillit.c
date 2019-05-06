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
# include <inttypes.h>
#include <time.h>
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
	find_coord(tet_arr, &coord_x, &coord_y);
	i = tet[0]->height;
	tet[0]->letter = letter;
	while (index < tet[0]->height)
	{// MEMORY LEAK? 2
		tet[0]->tet[index] = ft_strsub(tet_arr[0][coord_y], coord_x, tet[0]->width);
		coord_y++;
		tet[0]->tet[index][tet[0]->width] = '\0';
		tet[0]->x = 0;
		tet[0]->y = 0;
		tet[0]->first_try = true;
		//printf("tet[0]->height %d\n", tet[0]->height);
		chr_replace(tet[0]->tet[index], '#', letter, 4);
	//	printf("\"%s\"\n", tet[0]->tet[index]);
		i--;
		index++;
	}
//	printf("LETTER: \"%c\"\n", tet[0]->letter);
//	printf("--------------------------\n");
	if (size)
		cut_tet(&tet[-1], &tet_arr[-1], size - 1, letter - 1);
}

void	str_mem_aloc(t_tetro *tet[], uint8_t size)
{// MEMORY LEAK? 1
	tet[size]->tet = (char **)ft_memalloc(sizeof(char *) * tet[size]->height);
	if (size)
		str_mem_aloc(tet, size - 1);
}



char	**map_mem_aloc(char **map, int map_size)
{
	int8_t	i;

	i = 0;
	map = (char **)ft_memalloc(sizeof(char *) * (map_size + 1));
	while (i < map_size)
	{
		map[i] = ft_strnew(map_size);
		map[i] = (char *)ft_memset((void *)map[i], '.', map_size);
		map[i][map_size + 1] = '\0';
		i++;
	}
	return (map);
}

void	ft_arr_del(char **str_arr, int8_t size)
{
	int8_t	i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&str_arr[i]);
		i++;
	}
}

void	turn_back_time(t_tetro *tet[], uint8_t size)
{
	tet[0]->first_try = true;
	tet[0]->x = 0;
	tet[0]->y = 0;
	if (size)
		turn_back_time(&tet[-1], size - 1);
}

void	free_arr(t_tetro *tet[], uint8_t size)
{
	uint8_t	i;

	i = 0;
	while(i < size)
	{
		ft_arr_del(tet[i]->tet, tet[i]->height);
		i++;
	}
	
}


int8_t		set_map_size(t_tetro *tet[], uint8_t tet_amount)
{
	uint8_t	i;
	int8_t	map_size;
	uint8_t min_map_size;

	map_size = kr_sqrt(tet_amount * 4);
	if (map_size == 2)
		if((tet[0]->width != 2) && (tet[0]->height != 2))
			return (3);
	i = 0;
	if (map_size < 4)
	{
		while(i < tet_amount)
		{
			if ((tet[i]->height == 1 && tet[i]->width == 4) ||
				(tet[i]->width == 1 && tet[i]->height == 4))
				return (4);
			i++;
		}
	}
	return (map_size);
}

/*
** Varievble size = amount of tetromino
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
	int8_t	map_size;
	int8_t	result;
	char	**map;

	map = NULL;

//	printf("MAP SIZE %d\n", map_size);
//	map_size = kr_sqrt((size) * 4);
	if (struct_mem_aloc(tet, size) == -1)
			return (-1);
	size--;
	set_tet_height(tet, &tet_arr[size], size);
	set_tet_width(tet, &tet_arr[size], size);
	str_mem_aloc(tet, size);
	cut_tet(&tet[size], &tet_arr[size], size, 'A' + size);

	map_size = kr_sqrt((size + 1) * 4);
//	map_size = set_map_size(tet, size + 1);
//	printf("MAP SIZE %d\n", map_size);
//map_size = 8;
int i = 0;
	map = map_mem_aloc(map, map_size );
	result = solver(tet, map, map_size, size, i);
	while (result == SMALL_MAP)
	{
		printf("Call solver one more time\n");
		ft_arr_del(map, map_size);
		turn_back_time(&tet[size], size);
		tet[0]->first_try = true;
		map_size += 1;
		map = map_mem_aloc(map, map_size);
		result = solver(tet, map, map_size, size, i);
	}
	free_arr(tet, size);
	printf("Tet amount: %d\n", size + 1);
//	printf("------------\n");
	print_map(map, map_size);
	ft_arr_del(map, map_size);
//	sleep(20);
	return (0);
}

int		main(int argc, char **argv)
{
	if ((argc != 2) && error_msg(4))
		return (0);
	clock_t begin = clock();
	if ((check_file(argv[1]) == -1))
		return (0);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\033[36mtime:%f\n\033[0m", time_spent);
	//sleep(10);
	return (0);
}
