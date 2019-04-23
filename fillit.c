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

void discover_new_int()
{
	uint8_t			xs;
	int8_t			int8_xs;
	uint16_t		xs_max;

	xs = 255;
	xs_max = 65535;
	int8_xs = 124;
	printf("uint8_t: %zu, value: %hhu\n", sizeof(uint8_t), xs);
	printf("int8_t: %zu, value: %hhu\n", sizeof(int8_t), int8_xs);
	printf("uint16_t: %zu, value: %hu\n\n", sizeof(uint16_t), xs_max);
	printf("unsigned short int %zu \n", (sizeof(unsigned short int)));
	printf("int %zu \n", (sizeof(int)));
}

short int	check_file()
{
	return (3);
}

void		print_list(t_tetra *top)
{
	t_tetra		*head;

	head = top;
	while(head)
	{
		printf("%c\n", head->letter);
		head = head->next;
	}
}

int		fillit()
{
	int tet_amount;

	tet_amount = check_file();
	return (0);
}

void		coordinat_x(uint8_t x0, uint8_t x1, uint8_t x2, uint8_t x3)
{
	static uint8_t		i;

	shape[i].x[0] = x0;
	shape[i].x[1] = x1;
	shape[i].x[2] = x2;
	shape[i].x[3] = x3;
	shape[i].index = i;
	i++;
//	printf("%hhu\n", shape[0].shape);
	printf("%hhu\n", i);
	return ;
}

void		coordinat_y(uint8_t y0, uint8_t y1, uint8_t y2, uint8_t y3)
{
	static uint8_t		i;

	shape[i].y[0] = y0;
	shape[i].y[1] = y1;
	shape[i].y[2] = y2;
	shape[i].y[3] = y3;
	shape[i].index = i;
	i++;
//	printf("%hhu\n", shape[0].shape);
	printf("%hhu\n", i);
	return ;
}

const int		open_file(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	printf("fd %s\n", file);
	printf("fd %d\n", fd);
	if (fd == -1)
	{
		error(1);
		return (-1);
	}
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

int8_t	check_map(const int fd)
{
	char	buff[5];
	ssize_t	byte;
	short int	line;
	short int buff_size; //547
	short int last_line;

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

int		main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		error(4);
		return (0);
	}
	fd = open_file(argv[1]);
	if (fd == -1)
		return (0);
	if (check_map(fd) == -1)
	{
		error(2);
		return (-1);
	}
	printf("Success\n");
	
	return (0);
}
