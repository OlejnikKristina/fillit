/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 15:54:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/13 19:51:28 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tet_amount(uint8_t tet_amount)
{
	ft_putstr("Amount of tetromino: ");
	ft_putnbr((int)tet_amount);
	ft_putchar('\n');
}

void	fill_colors(t_colors *fill)
{
	short unsigned int	i;
	short unsigned int	y;
	char				*array[15];

	i = 0;
	y = 0;
	array[0] = RED;
	array[1] = PINK;
	array[2] = YELLOW;
	array[3] = DARK_BLUE;
	array[4] = GREEN;
	array[5] = BLUE;
	array[6] = WHITE;
	array[7] = REG_PINK;
	fill->letter = "ABCDEFGHIKLMNOPQRSTVXYZ";
	fill->colors = (char **)malloc(sizeof(char *) * 26);
	while (i < 26)
	{
		fill->colors[i] = array[y];
		i++;
		y++;
		if (y == 8)
			y = 0;
	}
}

void	print_color_line(t_colors *fill, char *line, int map_size)
{
	short int i;
	short int y;

	i = 0;
	y = 0;
	while (i < map_size)
	{
		y = findchr(fill->letter, line[i]);
		if (y != -1)
			ft_putstr(fill->colors[y]);
		else
			ft_putstr(WHITE);
		ft_putchar(line[i]);
		i++;
	}
}

void	print_colorfull(char **map, int map_size)
{
	t_colors	color;
	int8_t		i;

	i = 0;
	fill_colors(&color);
	while (i < map_size)
	{
		print_color_line(&color, map[i], map_size);
		i++;
		if (i < map_size)
			ft_putchar('\n');
	}
	ft_putstr(WHITE);
	free(color.colors);
}

void	print_map(char **map, int map_size)
{
	int8_t		i;

	i = 0;
	if (PRINT_WITH_COLOR == true)
		print_colorfull(map, map_size);
	else
	{
		while (i < map_size)
		{
			ft_putstr(map[i]);
			ft_putchar('\n');
			i++;
		}
	}
}
