/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/14 20:28:10 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/13 19:39:09 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	if (fd == -1 && error_msg(1))
		return (-1);
	if ((check_map(fd, &tet_amount, var, for_norm) == -1) && error_msg(2))
		return (-1);
	if ((tet_amount > 26) && error_msg(5))
		return (-1);
	close(fd);
	fd = open_file(file);
	if (fd == -1 && error_msg(1))
		return (-1);
	if ((check_shape(fd, tet_amount, 0) == -1) && error_msg(2))
		return (-1);
	return (0);
}

/*
** clock_t begin = clock();
** clock_t end = clock();
** double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
** printf("\033[36mtime:%f\n\033[0m", time_spent);
*/

int		main(int argc, char **argv)
{
	if ((argc != 2) && error_msg(4))
		return (0);
	if ((check_file(argv[1]) == -1))
		return (0);
	return (0);
}
