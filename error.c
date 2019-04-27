/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 15:54:18 by krioliin      #+#    #+#                 */
/*   Updated: 2019/04/20 15:54:19 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	chr_replace(char *str, int target, int replace, int32_t len)
{
	if (-1 < len)
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

int		open_file(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if ((fd == -1) && error(1))
		return (-1);
	return (fd);
}

uint8_t	error(int error)
{
	ft_putstr("Error. ");
	if (error == 1)
		ft_putstr("Can not open a file\n");
	else if (error == 2)
		ft_putstr("File has invalid input\n");
	else if (error == 3)
		ft_putstr("Not new line in the end of tetrominos\n");
	else if (error == 4)
		ft_putstr("Send as parraeter one file.\n");
	else if (error == 5)
		ft_putstr("Not correct input. ");
	else if (error == 6)
		ft_putstr("Incorrect shape of tetramino\n");
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
	if ((fd == -1) && error(1))
		return (-1);
	if (((check_map(fd, &tet_amount, var, for_norm) == -1)
	|| (tet_amount > 26)) && error(2))
		return (-1);
	close(fd);
	fd = open_file(file);
	if ((fd == -1) && error(1))
		return (-1);
	if ((check_shape(fd, tet_amount) == -1) && error(2))
		return (-1);
	return (0);
}
