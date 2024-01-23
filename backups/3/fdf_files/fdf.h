/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:01:08 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/23 13:32:15 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../mlx_linux/mlx.h"
# include <math.h>
# include "X11/X.h"
# include "X11/keysym.h"
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct point_coordinate
{
	int	x;
	int	y;
	int	z;
}		t_point_coordinate;

void	fdf(char *file);
int		**get_file_coordinates(char *file_name, int y_max);
void	free_matrix(int **matrix, int matrix_len);
void	isometric_projection(int **matrix);

#endif
