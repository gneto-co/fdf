/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:09:59 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/23 13:44:49 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(int **matrix)
{
    // void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	// mlx_loop(mlx);

// 

    void	*mlx_ptr;

    mlx_ptr = mlx_init();
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}
