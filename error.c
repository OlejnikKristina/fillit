/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 15:54:18 by krioliin      #+#    #+#                 */
/*   Updated: 2019/04/20 15:54:19 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	error(int error)
{
	ft_putstr("Error. ");
	if (error == 1)
		ft_putstr("Can bot open a file\n");
	else if (error == 2)
		ft_putstr("File is not valid\n");
	else if (error == 3)
		ft_putstr("Not new line in the end of tetrominos\n");
	else if (error == 4)
		ft_putstr("Send as parraeter only one file.\n");
	else if (error == 5)
		ft_putstr("\n");
	else if (error == 6)
		ft_putstr("\n");
	else
		return ;
}