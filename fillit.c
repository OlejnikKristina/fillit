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

int		error()
{
	ft_putstr("error\n");
	return (1);
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

int		read_tet(char *file)
{
	ssize_t		byte;

	t_tetra		*tet;
	char		buff[6];
	short int	fd;
	short int	i;

	
/*
	fd = open(file, O_RDWR);
	i = 0;
	if (fd < 0  && error())
		return(0);
	while (byte > -1)
	{
		byte = read(fd, buff, 5);
		buff[4] = '\0';

	}*/
	return (0);
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

void		coordinat_x(uint8_t y0, uint8_t y1, uint8_t y2, uint8_t y3)
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

int		main(int argc, char **argv)
{
	
	return (0);
}


