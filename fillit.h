/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/14 20:28:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/15 21:15:45 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILIT_H
#define FILIT_H
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

# include <unistd.h>
# include <sys/stat.h> 
# include <fcntl.h>

# define PROTECT(x) if (!(x)) return (NULL);

typedef struct			s_tetra
{
	unsigned short int	x[4];
	unsigned short int	y[4];
	char				letter;
	struct s_tetra		*next;
}						t_tetra;

# endif
//arr[0]->coord1->x;
t_tet   *arr[26];
//t_tet	arr[26][1];
///tetarr = arr[sizeof(t_tet) * 26];

//arr[0] = (t_tet)malloc(sizeof(t_tet));

char *str[3];

str[0] = malloc(100);
str[1] = &string;

typedef struct	s_tet
{
	t_coord		coord1;
	t_coord		coord2;
	t_coord		coord3;
	t_coord		coord4;
	char		letter;
}				t_tet;
/*
char *str;

str[0] = c;

t_tet *item;

* -> DATA, DATA, DATA;
*/
typedef struct s_coord
{
	short int x;
	short int y;
}				t_coord;
