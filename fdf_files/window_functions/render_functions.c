/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:24:00 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/08 20:08:48 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	calc_up_color(t_data *data, int z)
{
	return ((z * (COLOR_MAX)) / (data->map.z_max - data->map.z_min));
}

int	calc_down_color(t_data *data, int z)
{
	return (((data->map.z_max - z) * (COLOR_MIN)) / (data->map.z_max
			- data->map.z_min));
}

void	draw_area(t_data *data, t_rect sqr)
{
	render_line(data, (t_line){sqr.x, sqr.y, sqr.x + sqr.width, sqr.y, 53});
	render_line(data, (t_line){sqr.x, sqr.y, sqr.x, sqr.y + sqr.height, 53});
	render_line(data, (t_line){sqr.x + sqr.width, sqr.y, sqr.x + sqr.width,
		sqr.y + sqr.height, 53});
	render_line(data, (t_line){sqr.x, sqr.y + sqr.height, sqr.x + sqr.width,
		sqr.y + sqr.height, 53});
}
