/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 15:50:55 by krioliin      #+#    #+#                 */
/*   Updated: 2019/04/24 15:50:58 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 15:48:31 by krioliin      #+#    #+#                 */
/*   Updated: 2019/04/24 15:48:33 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

const int		open_file(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if ((fd == -1) && error(1))
		return (-1);
	return (fd);
}
/*
** Checks if first 4 chars in line is dots or hash
** Checks if 5th chars is \n
** Checks if there's 4 hash per tetramino block
*/
int8_t	check_line(char buff[5], short int	line)
{
	uint8_t 			i;
	static short int 	hash;

	i = 0;
	if (line == 0)
		hash = 0;
	while (i <= 3)
	{
		if (buff[i] == '#')
			hash++;
		if (buff[i] != '.' && buff[i] != '#')
			return (-1);
		i++;
	}
	if (buff[4] != '\n' && buff[4] != '\0')
		return (-1);
	if (line == 3 && hash != 4)
		return (-1);
	return (0);
}

int8_t	check_map(const int fd, short int *tet_amount)
{
	char		buff[5];
	ssize_t		byte;
	short int	line;
	short int 	buff_size;
	short int 	last_line;

	byte = read(fd, buff, 5);
	line = 0;
	last_line = 0;
	while (byte > 0)
	{
		if (line == 4)
		{
			if (buff[0] != '\n')
				return (-1);
			line = 0;
			buff_size = 5;
			last_line = 1;
			*tet_amount += 1;
		}
		else if (line <= 3)
		{
			buff_size = 5;
			if (check_line(buff, line) == -1)
				return (-1);
			line++;
			last_line = 0;
		}
		if (line == 4)
			buff_size = 1;
		ft_bzero(buff, 5);
		byte = read(fd, buff, buff_size);
	}
	return ((last_line) ? -1 : 0);
}

int8_t	check_shape_two(char tetrs[][4][6], int amount)
{
	int			line;
	int			token;

	line = 0;
	while (line < 4)
	{
		token = -1;
		line++;
		while (token <= 4)
		{
			token++;
			if (tetrs[0][line][token] == '#')
			{
				if ((line == 3 ) && (tetrs[0][line - 1][token] == '#'))
					continue ;
				if (tetrs[0][line + 1][token] == '#')
					continue ;
				if (tetrs[0][line][token + 1] == '#')
					continue ;
				if (tetrs[0][line][token - 1] == '#')
					continue ;
				else
					printf("FAIL. Tetramino %d line %d token %d\n", amount, line, token);
			}
		}
	}
	return ((0 <= amount - 1) ? check_shape_two(&tetrs[-1], amount - 1) : 0);
}

int8_t	check_shape(const int fd, short int tet_amount)
{
	char	tetrs[tet_amount][4][6];
	char	buff[5];
	ssize_t	byte;
	int		i;
	int		line;

	i = 0;
	line = 0;
	while (i < tet_amount)
	{
		if (line == 4)
		{
			byte = read(fd, buff, 1);
			line = 0;
			i++;
			continue ;
		}
		byte = read(fd, buff, 5);
		ft_strncpy(tetrs[i][line], buff, 5);
		tetrs[i][line][5] = '\0';
		line++;
	}
	printf("str:\"%s\"\n", tetrs[0][0]);
	check_shape_two(&tetrs[tet_amount - 1], tet_amount - 1);
	return (0);
}

int8_t	check_file(char *file)
{
	int		fd;
	short int	tet_amount;

	tet_amount = 1;
	fd = open_file(file);
	if ((fd == -1) && error(1))
		return (-1);
	if (((check_map(fd, &tet_amount) == -1) || (tet_amount > 26)) && error(2))
		return (-1);
	close(fd);
	fd = open_file(file);
	if ((fd == -1) && error(1))
		return (-1);
	check_shape(fd, tet_amount);
	printf("tet amount:%hd\n", tet_amount);
	
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
