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

const int		open_file(const char *file)
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
	{
		ft_putstr("Not correct input. ");
		ft_putstr("Tetramino blox has to be attached to each other.\n");
	}
	else if (error == 6)
		ft_putstr("Incorrect shape of tetramino\n");
	else
		return (1);
	return (1);
}
