/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:11 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/07 23:14:37 by gneto-co         ###   ########.fr       */
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

	ft_printf(
		"\nFdf controls:\n"
		"\n(A) \t\t: move image left"
		"\n(D) \t\t: move image right"
		"\n(W) \t\t: move image up"
		"\n(S) \t\t: move image down"
		"\n"
		"\n(Up Arrow) \t: rotate forward"
		"\n(Down Arrow) \t: rotate backward"
		"\n(Left Arrow)   \t: zoom in"
		"\n(Right Arrow) \t: zoom out"
		"\n"
		"\n(R) \t\t: increase height"
		"\n(F) \t\t: decrease height"
		"\n"
		"\n(C) \t\t: increase color"
		"\n(V) \t\t: decrease color"
		"\n(X) \t\t: reset figure"
		"\n"
		);

	// starting the window loop
	pw(map);
	
	free_matrix((map.matrix), y_max);
}
