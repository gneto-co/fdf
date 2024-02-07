/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:15:29 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/07 10:19:54 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point iso(t_data *data ,t_point p)
{	
	t_point p2;
	static float s = 1;
	float speed = 0.0008;
	float max = 360;
	float min = -360;
	static float var = 1;
	
	// configurations
	int height;
	int zoom;
	int distance;
	int z_scale;

	// angles
	float angle;
	float vertical_angle;
	float y_angle; 

	// radian angles
	float radian_vertical_angle;
	float radian_angle;
	float radian_y_angle;

	//
	// AUTO INCREASE
	//

	// front and back
	if (var > max)
		s = 0;
	if (var <= min)
		s = 1;
	if (s == 1)
		var+=speed;
	else
		var-=speed;

	// only front
	// var += speed;

	// printf("\n-> %f", var);

	//
	//CONVERSION
	//

	// definitions
	height = 100; // 100
	z_scale = 30; // 30
	angle = 45; //45
	vertical_angle = 45; //45
	y_angle = 30; // 30

	// angle conversions
	radian_angle = angle * M_PI / 180.0;
	radian_vertical_angle = vertical_angle * M_PI / 180.0;
	radian_y_angle = y_angle * M_PI / 180.0;

	// isometric calculations
    p2.x = (p.x - p.y) * cos(radian_angle);
	p2.y = (p.x + p.y) * sin(radian_angle) * cos(radian_vertical_angle) - p.z * z_scale * sin(radian_vertical_angle);
    p2.y -= height;

	return(p2);
}

void draw_line_points(t_data *data, t_point p1, t_point p2)
{
	t_point ip1;
	t_point ip2;
	int awm;
	int ahm;

	ip1= iso(data, p1);
	ip2= iso(data, p2);

	// awm = (DRAW_WIDTH-(data->map.x_max*LINE_WIDTH))/1.5;
	awm = DRAW_WIDTH/2  - data->map.extra_width;
	ahm = ((DRAW_HEIGHT/(data->map.y_max+2))*2) - data->map.line_height - data->map.extra_height;
	// ahm = DRAW_HEIGHT/2;

	img_pix_put(&data->img, DRAW_WIDTH_START + awm, DRAW_HEIGHT_START + ahm,RED_PIXEL);
	render_p_line(data, (t_line){
		DRAW_WIDTH_START + awm + ip1.x, DRAW_HEIGHT_START + ahm + ip1.y, 
		DRAW_WIDTH_START + awm + ip2.x, DRAW_HEIGHT_START + ahm + ip2.y, 
		p1.z, p2.z});
}

static void	draw_x_lines(t_data *data)
{
	int	x;
	int	y;
	t_point p1;
	t_point p2;

	// draw x lines
	y = 0;
	while (y < data->map.y_max)
	{
		x = 0;
		while (x + 1 < data->map.x_max)
		{
			p1 = (t_point){data->map.line_width * x, data->map.line_height * y, data->map.matrix[y][x]};
			p2 = (t_point){data->map.line_width * (x+1), data->map.line_height * y, data->map.matrix[y][x+1]};
			draw_line_points(data, p1, p2);

			x++;
		}
		y++;
	}
}

static void	draw_y_lines(t_data *data)
{
	int	x;
	int	y;
	t_point p1;
	t_point p2;

	// draw y lines
	x = 0;
	while (x < data->map.x_max)
	{
		y = 0;
		while (y + 1 < data->map.y_max)
		{
			p1 = (t_point){data->map.line_width * x, data->map.line_height * y, data->map.matrix[y][x]};
			p2 = (t_point){data->map.line_width * x, data->map.line_height * (y+1), data->map.matrix[y+1][x]};
			draw_line_points(data, p1, p2);
	
			y++;
		}
		x++;
	}
}

void	draw_map(t_data *data)
{	
	draw_area(data, (t_rect){DRAW_WIDTH_START, DRAW_HEIGHT_START, DRAW_WIDTH, DRAW_HEIGHT});
	draw_area(data, (t_rect){TEXT_WIDTH_START, TEXT_HEIGHT_START, TEXT_WIDTH, TEXT_HEIGHT});
	draw_x_lines(data);
	draw_y_lines(data);
}
