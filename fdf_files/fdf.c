/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:11 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/07 11:39:31 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char *file_name)
{
	int	y_max;
	t_map map;

	// just getting the file coordinates to a matrix
	y_max = ft_filelen(file_name);
	map = get_file_coordinates(file_name, y_max);

	// starting the window loop
	pw(map);
	
	free_matrix((map.matrix), y_max);
}
