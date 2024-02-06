/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:24:00 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/06 22:05:30 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

typedef struct s_rl
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		z_increment;
}			t_rl;

void	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
}

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

int calc_up_color(t_data *data, int z)
{
	ft_printf("\nz: %d\nz_min: %d\nz_max: %d\n",z,data->map.z_min,data->map.z_max);
	return((z*COLOR_MAX)/(data->map.z_max - data->map.z_min));
}

int calc_down_color(t_data *data, int z)
{
	return(((data->map.z_max - z)*COLOR_MAX)/(data->map.z_max - data->map.z_min));
}

static void	render_line_2(t_data *data, t_line line, t_rl rl)
{
	int color;
	int z = line.z0;
	
	while (1)
	{
		color = ft_rgb_to_int(
			calc_down_color(data, z),
			calc_up_color(data, z),
			250
		);
		img_pix_put(&data->img, line.x0, line.y0, color);

		printf("\n\n%d\n\n",z);
		

		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		rl.e2 = 2 * rl.err;
		if (rl.e2 > -rl.dy)
		{
			rl.err = rl.err - rl.dy;
			line.x0 = line.x0 + rl.sx;
		}
		if (rl.e2 < rl.dx)
		{
			rl.err = rl.err + rl.dx;
			line.y0 = line.y0 + rl.sy;
			z += rl.z_increment;
		}
	}
}

int max(int a, int b) 
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void	render_line(t_data *data, t_line line)
{
	t_rl	rl;

	rl.dx = abs(line.x1 - line.x0);
	rl.dy = abs(line.y1 - line.y0);
	if (line.x0 < line.x1)
		rl.sx = 1;
	else
		rl.sx = -1;
	if (line.y0 < line.y1)
		rl.sy = 1;
	else
		rl.sy = -1;
	rl.err = rl.dx - rl.dy;
	
	// Calcula o incremento de z
	int delta_z = line.z1 - line.z0;
	int total_steps = max(abs(line.x1 - line.x0), abs(line.y1 - line.y0));
	rl.z_increment = (float)delta_z / total_steps;
	
	render_line_2(data, line, rl);
}
// algoritmo de Bresenham
