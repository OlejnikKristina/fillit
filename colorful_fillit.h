/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colorful_fillit.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 15:54:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/13 19:28:12 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORFUL_FILLIT_H
# define COLORFUL_FILLIT_H

# define PRINT_WITH_COLOR true
# define N 65000

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define DARK_BLUE "\033[1;34m"
# define PINK "\033[1;35m"
# define BLUE "\033[1;36m"
# define WHITE "\033[1;37m"
# define GRAY "\033[1;30m"
# define REG_PINK "\033[0;35m"

typedef struct	s_colors
{
	char		*letter;
	char		**colors;
}				t_colors;

#endif
