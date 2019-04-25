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

#include <stdio.h>
#include "fillit.h"

int8_t	check_block(char tetrs[][4][6], int8_t line, int8_t hash)
{
	int8_t	neighbor;

	neighbor = 0;
	if ((hash != 3) && (tetrs[0][line][hash + 1] == '#'))
		neighbor++;
	if ((hash != 0) && (tetrs[0][line][hash - 1] == '#'))
		neighbor++;
	if ((line != 0) && (tetrs[0][line - 1][hash] == '#'))
		neighbor++;
	if ((line != 3) && (tetrs[0][line + 1][hash] == '#'))
		neighbor++;
	return (neighbor);
}

int8_t	check_tet_shape(char tetrs[][4][6], short int amount)
{
	int8_t	line;
	int8_t	token;
	int8_t	neighbor;

	token = 0;
	line = 0;
	neighbor = 0;
	while (line < 4)
	{
		token = 0;
		while (token < 4)
		{
			if (tetrs[0][line][token] == '#')
				neighbor += check_block(&tetrs[0], line, token);
			token++;
		}
		line++;
	}
	if ((neighbor != 6) && (neighbor != 8))
		return (-1);
	if ((0 <= amount - 1))
		if (check_tet_shape(&tetrs[-1], amount - 1) == -1)
			return (-1);
	return (0);
}

int8_t	check_shape(const int fd, short int tet_amount)
{
	char	tetrs[tet_amount][4][6];
	char	buff[5];
	ssize_t	byte;
	int8_t	i;
	int8_t	line;

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
	if (check_tet_shape(&tetrs[tet_amount - 1], tet_amount - 1) == -1)
		return (-1);
	algoritm(tetrs, tet_amount);
	return (0);
}

/*
** Checks if first 4 chars in line is dots or hash
** Checks if 5th chars is \n
** Checks if there's 4 hash per tetramino block
*/

int8_t	check_line(char buff[5], short int line)
{
	uint8_t				i;
	static short int	hash;

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
	if (buff[4] != '\n')
		return (-1);
	if (line == 3 && hash != 4)
		return (-1);
	return (0);
}

int8_t	check_map(const int fd, int8_t *tet_num, int line, int last_line)
{
	char		buff[5];
	ssize_t		byte;

	byte = read(fd, buff, 5);
	while (byte > 0)
	{
		if ((line == 4) && (last_line = 1) && (*tet_num += 1))
		{
			if (buff[0] != '\n')
				return (-1);
			line = 0;
		}
		else if (line <= 3)
		{
			if (check_line(buff, line) == -1)
				return (-1);
			line++;
			last_line = 0;
		}
		if ((line == 4) && (byte = read(fd, buff, 1)))
			continue ;
		ft_bzero(buff, 5);
		byte = read(fd, buff, 5);
	}
	return ((last_line || line != 4) ? -1 : 0);
}
