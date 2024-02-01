/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:09:59 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/01 13:34:02 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, BLACK_PIXEL);
	line_4(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	return (0);
}
// thats what will repeat every time in mlx cycle

int	pw(int **matrix)
{
	t_data	data;

	if (initialize_data(&data, matrix) == MLX_ERROR)
		return (MLX_ERROR);
	setup_image(&data);
	setup_hooks(&data);
	free_mlx_stuff(&data);
}
