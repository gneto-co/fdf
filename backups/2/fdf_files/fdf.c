/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:11 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/19 16:12:23 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include "fdf.h"

void	fdf(char *file_name)
{
	int	**matrix;
	int	y_max;

	y_max = ft_filelen(file_name);
	matrix = get_file_coordinates(file_name, y_max);
	
	ft_printf(
		"%d - %d - %d - %d\n"
		"%d - %d - %d - %d\n"
		"%d - %d - %d - %d\n"
		"%d - %d - %d - %d\n"
		,matrix[0][0], matrix[0][1],matrix[0][2], matrix[0][3]
		,matrix[1][0], matrix[1][1],matrix[1][2], matrix[1][3]
		,matrix[2][0], matrix[2][1],matrix[2][2], matrix[2][3]
		,matrix[3][0], matrix[3][1],matrix[3][2], matrix[3][3]
	);

	// isometric_projection(matrix);
	
	free_matrix(&(*matrix), y_max);
}
