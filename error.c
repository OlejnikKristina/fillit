/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 15:54:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/08 15:57:20 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	print_map(char **map, int map_size)
{
	int8_t i;

	i = 0;
	while(i < map_size)
	{
		printf("%s\n", map[i]);
		i++;
	}
	
}

int		kr_sqrt(int nb)
{
	int	sqrt;
	int	sqrt1;
	int	res;
	int	res1;

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

int		open_file(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if ((fd == -1) && error_msg(1))
		return (-1);
	return (fd);
}

uint8_t		error_msg(int error)
{
	ft_putstr("error\n");
	if (error == 1)
		ft_putstr("Can not open a file");
	else if (error == 2)
		ft_putstr("File has invalid input");
	else if (error == 3)
		ft_putstr("Not new line in the end of tetrominos");
	else if (error == 4)
		ft_putstr("Send as parraeter one file.");
	else if (error == 5)
		ft_putstr("Not correct input.");
	else if (error == 6)
		ft_putstr("Incorrect shape of tetramino");
	else
		return (1);
	return (1);
}

int8_t	check_file(char *file)
{
	int			fd;
	int8_t		tet_amount;
	int8_t		var;
	int8_t		for_norm;

	tet_amount = 1;
	var = 0;
	for_norm = 0;
	fd = open_file(file);
	if ((fd == -1) && error_msg(1))
		return (-1);
	if (((check_map(fd, &tet_amount, var, for_norm) == -1)
	|| (tet_amount > 26)) && error_msg(2))
		return (-1);
	close(fd);
	fd = open_file(file);
	if ((fd == -1) && error_msg(1))
		return (-1);
	if ((check_shape(fd, tet_amount) == -1) && error_msg(2))
		return (-1);
	return (0);
}
