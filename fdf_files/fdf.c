/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:11 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/08 20:07:30 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_instructions(void)
{
	ft_putstr("\nFdf controls:\n");
	ft_putstr("\n(A) \t\t: move image left");
	ft_putstr("\n(D) \t\t: move image right");
	ft_putstr("\n(W) \t\t: move image up");
	ft_putstr("\n(S) \t\t: move image down");
	ft_putstr("\n");
	ft_putstr("\n(E) \t\t: move speed increase");
	ft_putstr("\n(Q) \t\t: move speed decrease");
	ft_putstr("\n");
	ft_putstr("\n(Up Arrow) \t: rotate forward");
	ft_putstr("\n(Down Arrow) \t: rotate backward");
	ft_putstr("\n(Left Arrow) \t: rotate to the left");
	ft_putstr("\n(Right Arrow) \t: rotate to the right");
	ft_putstr("\n");
	ft_putstr("\n(I) \t\t: zoom in");
	ft_putstr("\n(O) \t\t: zoom out");
	ft_putstr("\n(R) \t\t: increase height");
	ft_putstr("\n(F) \t\t: decrease height");
	ft_putstr("\n");
	ft_putstr("\n(C) \t\t: increase color");
	ft_putstr("\n(V) \t\t: decrease color");
	ft_putstr("\n(X) \t\t: reset figure");
	ft_putstr("\n");
}

void	fdf(char *file_name)
{
	int		y_max;
	t_map	map;

	y_max = ft_filelen(file_name);
	map = get_file_coordinates(file_name, y_max);
	print_instructions();
	pw(map);
	free_matrix((map.matrix), y_max);
}
