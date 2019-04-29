/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_algoritm.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/27 19:31:42 by krioliin      #+#    #+#                 */
/*   Updated: 2019/04/27 19:31:43 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		ft_skrt(int nb)
{
	int sqrt;
	int	sqrt2;
	int	res1;
	int	res2;

	sqrt = 1;
	sqrt2 = 2;
	while (nb >= sqrt)
	{
		res1 = sqrt2 * sqrt2;
		if (res1 == nb)
			return (sqrt2);
		res2 = sqrt * sqrt;
		if ((res1 > nb) && (nb <= res2))
			return (sqrt);
		sqrt2++;
		sqrt++;
	}
	return (0);
}

int		solver(t_tetro *tet[], int8_t size)
{
	int map_size;

	map_size = ft_sqrt(24);
	if (tet[0])
		printf("map_size %d\n", ft_skrt(32));
	printf("size %hhu\n", size);
	return(0);
}