/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   auxiliary_funcs.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/14 20:28:10 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/12 19:13:58 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	turn_back_time(t_tetro tet[], uint8_t size)
{
	tet[0].first_try = true;
	tet[0].x = 0;
	tet[0].y = 0;
	if (size)
		turn_back_time(&tet[-1], size - 1);
}

void	del_arr(char **str_arr, int8_t size)
{
	int16_t	i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&str_arr[i]);
		i++;
	}
	free(str_arr);
}

void	clean_struct(t_tetro tet[], uint8_t size)
{
	uint16_t	i;

	i = 0;
	while (i <= size)
	{
		del_arr(tet[i].tet, tet[i].height);
		i++;
	}
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

void	del_tet(char **map, int target, int replace, int map_size)
{
	int8_t i;

	i = 0;
	while (i < map_size)
	{
		chr_replace(map[i], target, replace, map_size);
		i++;
	}
}
