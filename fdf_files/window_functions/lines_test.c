/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:50:55 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/29 12:30:28 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	line_1(t_data *data)
{
	render_rect(&data->img, (t_rect){0, WINDOW_HEIGHT / 4, WINDOW_WIDTH, 1,
		BLUE_PIXEL});
	render_rect(&data->img, (t_rect){0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, 1,
		GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, (WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 4),
		WINDOW_WIDTH, 1, BLUE_PIXEL});
	render_rect(&data->img, (t_rect){WINDOW_WIDTH / 4, 0, 1, WINDOW_HEIGHT,
		BLUE_PIXEL});
	render_rect(&data->img, (t_rect){WINDOW_WIDTH / 2, 0, 1, WINDOW_HEIGHT,
		RED_PIXEL});
	render_rect(&data->img, (t_rect){(WINDOW_WIDTH / 2 + WINDOW_WIDTH / 4), 0,
		1, WINDOW_HEIGHT, BLUE_PIXEL});
	return (0);
}

int	line_2(t_data *data)
{
	int	x_number;
	int	y_number;
	int	i;
	int	n;

	n = 10;
	x_number = n;
	y_number = n;
	i = 0;
	while (i < x_number)
	{
		render_rect(&data->img, (t_rect){0, ((WINDOW_HEIGHT / (x_number + 1))
				* (i + 1)), WINDOW_WIDTH, 1, BLUE_PIXEL});
		i++;
	}
	i = 0;
	while (i < y_number)
	{
		render_rect(&data->img, (t_rect){((WINDOW_WIDTH / (y_number + 1)) * (i
					+ 1)), 0, 1, WINDOW_HEIGHT, BLUE_PIXEL});
		i++;
	}
	return (0);
}
