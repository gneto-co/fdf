/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawn_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:15:29 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/02 13:31:52 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	no_transformation(t_data *data)
{
	int	x;
	int	y;
	int line_width;
	int line_height;

	// ft_printf("x max: %d, y max: %d\n", data->map.x_max, data->map.y_max);
	line_width = DRAWN_AREA_WIDTH / (data->map.x_max - 1);
	line_height = DRAWN_AREA_HEIGHT / (data->map.y_max - 1);

	// drawn x lines
	y = 0;
	while (y < data->map.y_max)
	{
		x = 0;
		while (x + 1 < data->map.x_max)
		{
			render_line(&data->img, (t_line){
				MARGIN_WIDTH + line_width * x, MARGIN_HEIGHT + line_height * y,
				MARGIN_WIDTH + line_width * (x+1), MARGIN_HEIGHT + line_height * y,
				WHITE_PIXEL
			});
			x++;
		}
		y++;
	}
	// drawn y lines
	x = 0;
	while (x < data->map.x_max)
	{
		y = 0;
		while (y + 1 < data->map.y_max)
		{
			render_line(&data->img, (t_line){
				MARGIN_WIDTH + line_width * x, MARGIN_HEIGHT + line_height * y,
				MARGIN_WIDTH + line_width * x, MARGIN_HEIGHT + line_height * (y+1),
				WHITE_PIXEL
			});
			y++;
		}
		x++;
	}
}

void	drawn_map(t_data *data)
{
	no_transformation(data);
}
