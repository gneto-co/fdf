/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:24:00 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/01 12:11:04 by gneto-co         ###   ########.fr       */
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

static void	render_line_2(t_img *img, t_line line, t_rl rl)
{
	while (1)
	{
		img_pix_put(img, line.x0, line.y0, line.color);
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

void	render_line(t_img *img, t_line line)
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
	render_line_2(img, line, rl);
}
// algoritmo de Bresenham
