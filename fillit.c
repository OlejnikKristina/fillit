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

int		error()
{
	ft_putstr("error\n");
	return (1);
}

t_tetra		*create_tet_list(t_tetra **top)
{
	t_tetra *head;
	t_tetra	*new_tet;

	if (!(*top))
	{
		PROTECT((*top) = (t_tetra *)malloc(sizeof(t_tetra)));
		(*top)->letter = 'A';
		(*top)->next = NULL;
		return ((*top));
	}
	head = (*top);
	while (head->next != NULL)
		head = head->next;
	PROTECT(new_tet = (t_tetra *)malloc(sizeof(t_tetra)));
	head->next = new_tet;
	new_tet->letter = head->letter;
	++new_tet->letter;
	new_tet->next = NULL;
	return (new_tet);
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
	t_tetra		*top;
	t_tetra		*tet;
	t_tetra		*tet2;
	t_tetra		*tet3;

	top = create_tet_list(&top);
	tet = create_tet_list(&top);
	tet2 = create_tet_list(&top);
	tet3 = create_tet_list(&top);

	printf("top->letter %c\n", top->letter);
	print_list(top);
/*	printf("top - %p\n", top);
	printf("top->next %p, real next %p\n", top->next, tet);
	printf("tet->next %p, tet2 - %p\n", tet->next, tet2);
	printf("tet2->next %p, tet3 - %p\n", tet2->next, tet3);
	printf("top - %p\n", top->next);*/
	return (0);
}

int		main(int argc, char **argv)
{/*
	if (argc == 1)
	{
		read_tet(argv[1]);
	}*/
	printf("ssize_t %lu\n", sizeof(ssize_t));
	printf("short int %lu\n", sizeof(short int));
//	fillit();

	t_tet arr[26];

//	arr[0] = (t_tet *)malloc(sizeof(t_tet));
	return (0);
}


