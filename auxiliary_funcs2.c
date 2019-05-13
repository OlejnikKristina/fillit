/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   auxiliary_funcs2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 15:54:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/13 19:50:00 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		kr_sqrt(int nb)
{
	int sqrt;
	int sqrt1;
	int res;
	int res1;

	sqrt = 1;
	sqrt1 = 2;
	while (sqrt1 <= nb)
	{
		res = sqrt * sqrt;
		if (res == nb)
			return (res);
		res1 = sqrt1 * sqrt1;
		if (res1 == nb)
			return (sqrt1);
		if ((res < nb) && (nb < res1))
			return (sqrt1);
		sqrt++;
		sqrt1++;
	}
	return (0);
}

void	chr_replace(char *str, int target, int replace, int32_t len)
{
	if (0 < len)
	{
		while (len)
		{
			if (*str == target)
				*str = replace;
			str++;
			len--;
		}
	}
	else
	{
		while (str)
		{
			if (*str == target)
				*str = replace;
			str++;
		}
	}
}

void	fix_norm(int8_t *tet_num, int *last_line, int *line)
{
	*line = 0;
	*tet_num += 1;
	*last_line = 0;
}

int		open_file(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

uint8_t	error_msg(int error)
{
	ft_putstr("error\n");
	if (error == 1)
		ft_putstr("Can\'t open a file\n");
	else if (error == 2)
		ft_putstr("File has invalid input\n");
	else if (error == 3)
		ft_putstr("Not new line in the end of tetrominos\n");
	else if (error == 4)
		ft_putstr("usage: Send as parameter one file.\n");
	else if (error == 5)
		ft_putstr("Too many tetramino.\n");
	else
		return (1);
	return (1);
}
