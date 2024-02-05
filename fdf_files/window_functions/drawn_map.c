/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawn_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:15:29 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/05 22:49:18 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point convert_to_iso(t_data *data ,t_point p)
{	
	t_point p2;
	
	p2.x = (p.x-p.z)/sqrt(3);
	p2.y = (p.x+2*p.y+p.z)/sqrt(6);
	
	return(p2);
}

void drawn_line_points(t_data *data, t_point p1, t_point p2)
{
	render_line(&data->img, (t_line){
		MARGIN_WIDTH + p1.x, MARGIN_HEIGHT + p1.y, 
		MARGIN_WIDTH + p2.x, MARGIN_HEIGHT + p2.y, WHITE_PIXEL});
}

static void	no_transformation(t_data *data)
{
	int	x;
	int	y;
	t_point p1;
	t_point p2;

	// ft_printf("x max: %d, y max: %d\n", data->map.x_max, data->map.y_max);

	// drawn x lines
	y = 0;
	while (y < data->map.y_max)
	{
		x = 0;
		while (x + 1 < data->map.x_max)
		{
			// drawn a line between point (x,y) and point (x+1,y)

			// option 1
			p1 = (t_point){data->map.line_width * x, data->map.line_height * y, data->map.matrix[y][x]};
			p2 = (t_point){data->map.line_width * (x+1), data->map.line_height * y, data->map.matrix[y][x+1]};
			drawn_line_points(data, p1, p2);
			
			// option 2
			// render_line(&data->img, (t_line){
			// 	MARGIN_WIDTH + data->map.line_width * x, MARGIN_HEIGHT + data->map.line_height * y,
			// 	MARGIN_WIDTH + data->map.line_width * (x+1), MARGIN_HEIGHT + data->map.line_height * y,
			// 	WHITE_PIXEL
			// });
			
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
			// drawn a line between point (x,y) and point (x,y+1)
			
			// option 1
			p1 = (t_point){data->map.line_width * x, data->map.line_height * y, data->map.matrix[y][x]};
			p2 = (t_point){data->map.line_width * x, data->map.line_height * (y+1), data->map.matrix[y+1][x]};
			drawn_line_points(data, p1, p2);
			
			// option 2
			// render_line(&data->img, (t_line){
			// 	MARGIN_WIDTH + data->map.line_width * x, MARGIN_HEIGHT + data->map.line_height * y,
			// 	MARGIN_WIDTH + data->map.line_width * x, MARGIN_HEIGHT + data->map.line_height * (y+1),
			// 	WHITE_PIXEL
			// });
			
			y++;
		}
		x++;
	}
}





void	drawn_map(t_data *data)
{	
	no_transformation(data);



	
	// int n1 = -100;
	// int n2 = 100;
	// int altura = 10;
	// t_point pos = {W_WIDTH_CENTER, W_HEIGHT_CENTER};
	
	// t_point uL = {n1, n1, altura};
	// t_point uR = {n2, n1, altura};
	// t_point dL = {n1, n2, altura};
	// t_point dR = {n2, n2, altura};

	// drawn_line_points(data, uL, uR, pos);
	// drawn_line_points(data, dL, dR, pos);

	// drawn_line_points(data, uL, dL, pos);
	// drawn_line_points(data, uR, dR, pos);

	// // --------------------------------------------
	
	// t_point uL2 = convert_to_iso(data, uL);
	// t_point uR2 = convert_to_iso(data, uR);
	// t_point dL2 = convert_to_iso(data, dL);
	// t_point dR2 = convert_to_iso(data, dR);

	// drawn_line_points(data, uL2, uR2, pos);
	// drawn_line_points(data, dL2, dR2, pos);
	
	// drawn_line_points(data, uL2, dL2, pos);
	// drawn_line_points(data, uR2, dR2, pos);



	// printf(
	// 	"\n\nuR"
	// 	"\nOriginal: %d, %d"
	// 	"\nIsometric: %d, %d", 
	// 	uR.x, uR.y,
	// 	uR2.x, uR2.y
	// );
	// printf(
	// 	"\nuL"
	// 	"\nOriginal: %d, %d"
	// 	"\nIsometric: %d, %d", 
	// 	uL.x, uL.y,
	// 	uL2.x, uL2.y
	// );
	// printf(
	// 	"\ndR"
	// 	"\nOriginal: %d, %d"
	// 	"\nIsometric: %d, %d", 
	// 	dR.x, dR.y,
	// 	dR2.x, dR2.y
	// );
	// printf(
	// 	"\ndL"
	// 	"\nOriginal: %d, %d"
	// 	"\nIsometric: %d, %d", 
	// 	dL.x, dL.y,
	// 	dL2.x, dL2.y
	// );
}
