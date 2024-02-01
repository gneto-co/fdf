/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:11 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/01 13:32:05 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char *file_name)
{
	int	**matrix;
	int	y_max;

	// just getting the file coordinates to a matrix
	y_max = ft_filelen(file_name);
	matrix = get_file_coordinates(file_name, y_max);

	// starting the window and everything idk
	pw(matrix);
	
	free_matrix(&(*matrix), y_max);
}
