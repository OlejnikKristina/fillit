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

void		coordinat_x(uint8_t x0, uint8_t x1, uint8_t x2, uint8_t x3)
{
	static uint8_t		i;

	shape[i].x[0] = x0;
	shape[i].x[1] = x1;
	shape[i].x[2] = x2;
	shape[i].x[3] = x3;
	shape[i].index = i;
	i++;
/*
**	printf("%hhu\n", shape[0].shape);
*/
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
/*
**	printf("%hhu\n", shape[0].shape);
*/
	printf("%hhu\n", i);
	return ;
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
