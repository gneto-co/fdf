/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:50:55 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/23 11:48:29 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// algoritmo de Bresenham
// render line do normal lines
// render p line do projection lines
static void	render_p_line_2(t_data *data, t_line line, t_rl rl, int z)
{
	int	color;

	while (1)
	{
		color = ft_rgb_to_int(calc_down_color(data, z) + data->map.extra_color,
				calc_up_color(data, z), 250 - data->map.extra_color);
		if (line.x0 > DRAW_WIDTH_START && line.x0 < DRAW_WIDTH
			+ DRAW_WIDTH_START && line.y0 > DRAW_HEIGHT_START
			&& line.y0 < DRAW_HEIGHT + DRAW_HEIGHT_START)
			img_pix_put(&data->img, line.x0, line.y0, color);
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

int	max(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	else
	{
		return (b);
	}
}

void	render_p_line(t_data *data, t_line line)
{
	t_rl	rl;
	int		delta_z;
	int		total_steps;
	int		z;

	z = line.z0;
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
	delta_z = line.z1 - line.z0;
	total_steps = max(abs(line.x1 - line.x0), abs(line.y1 - line.y0));
	rl.z_increment = (float)delta_z / total_steps;
	render_p_line_2(data, line, rl, z);
}

static void	render_line_2(t_data *data, t_line line, t_rl rl)
{
	int	color;

	while (1)
	{
		img_pix_put(&data->img, line.x0, line.y0, BORDERS_COLOR);
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
		}
	}
}

void	render_line(t_data *data, t_line line)
{
	t_rl	rl;
	int		delta_z;
	int		total_steps;

	delta_z = line.z1 - line.z0;
	total_steps = max(abs(line.x1 - line.x0), abs(line.y1 - line.y0));
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
	render_line_2(data, line, rl);
}
