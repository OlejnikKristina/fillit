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

/*
while (token <= 4)
		{
			token++;
			if (tetrs[0][line][token] == '#')
			{
				if (((line == 3) && (tetrs[0][line - 1][token] == '#'))
				|| (tetrs[0][line + 1][token] == '#'))
					continue ;
				if ((tetrs[0][line][token + 1] == '#')
				|| (tetrs[0][line][token - 1] == '#') || (tetrs[0][line - 1][token] == '#'))
					continue ;
				else
				{
					printf("FAIL. Tetramino %d line %d token %d\n", amount, line, token);
					printf("%s\n", tetrs[0][0]);
					return (-1);
				}
			}
		}s
**printf("FAIL. Tetramino %d line %d token %d\n", amount, line, token);
*/

int		delimited_box(char tetrs[][4][6], int amount, int line_one, int line_two)
{
	int	token;
	int dots_one;
	int	dots_two;
	uint8_t	hash;
	uint8_t	i;

	token = 0;
	dots_one = 0;
	dots_two = 0;
	hash = 0;
	while (token < 4)
	{
		if (tetrs[0][line_one][token] == '.')
			dots_one++;
		if (tetrs[0][line_two][token] == '.')
			dots_two++;
		token++;
	}
	i = 0;
	while (i < 4)
	{
		if (hash == 4)
			break ;
		hash = 0;
		while (token < 4)
		{
			if (tetrs[0][i][token] == '#')
				hash++;
			token++;
		}
		token = 0;
		i++;
	}
	if ((dots_one == 4) && (dots_two == 4) && (hash != 4))
		return (-1);
	if (amount--)
		if (delimited_box(&tetrs[amount - 1], amount, line_one, line_two) == -1)
			return (-1);
	return (0);
}

int		dots(char *str)
{
	if (ft_strncmp((const char *)str, "....", 4) == 0)
	{
		printf("true");
		return (1);
	}
	else
		return (0);
}

int8_t	check_shape_algo(char tetrs[][4][6], int amount)
{
	int	line;
	int	token;

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
				if (((line == 3) && (tetrs[0][line - 1][token] == '#'))
				|| (tetrs[0][line + 1][token] == '#'))
					continue ;
				if ((tetrs[0][line][token + 1] == '#')
				|| (tetrs[0][line][token - 1] == '#') || (tetrs[0][line - 1][token] == '#'))
					continue ;
				else
				{
					printf("FAIL. Tetramino %d line %d token %d\n", amount, line, token);
					printf("%s\n", tetrs[0][0]);
					return (-1);
				}
			}
		}
	}
	return ((0 <= amount - 1) ? check_shape_algo(&tetrs[-1], amount - 1) : 0);
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
	if (delimited_box(&tetrs[tet_amount - 1], tet_amount - 1, 0, 2) == -1)
		return (-1);
	if (delimited_box(&tetrs[tet_amount - 1], tet_amount - 1, 1, 3) == -1)
		return (-1);
	return (check_shape_algo(&tetrs[tet_amount - 1], tet_amount - 1));
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
	if ((check_shape(fd, tet_amount) == -1) && error(6))
		return (-1);
//	printf("tet amount:%hhd\n", tet_amount);
	return (0);
}
