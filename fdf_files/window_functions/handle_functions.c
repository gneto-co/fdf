/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:06:48 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/08 12:00:17 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	// zoom 
	if (keysym == XK_i)
	{
		data->map.extra_z += 0.5;
		data->map.line_width ++;
		data->map.line_height ++;
	}
	if (keysym == XK_o && data->map.line_width > 0)
	{
		// data->map.extra_z -= 0.2;
		data->map.line_width --;
		data->map.line_height --;
	}
	//
	if (keysym == XK_Left)
		data->map.extra_angle+=5;
	if (keysym == XK_Right)
		data->map.extra_angle-=5;
	if (keysym == XK_Up)
		data->map.extra_vertical_angle+=5;
	if (keysym == XK_Down)
		data->map.extra_vertical_angle-=5;
	//
	static int speed = 5;
	if (keysym == XK_e)
		speed++;
	if (keysym == XK_q)
		speed--;
	if (keysym == XK_w)
		data->map.extra_height+=speed;
	if (keysym == XK_s)
		data->map.extra_height-=speed;
	if (keysym == XK_a)
		data->map.extra_width+=speed;
	if (keysym == XK_d)
		data->map.extra_width-=speed;
	//
	if (keysym == XK_r)
		data->map.extra_z+=1;
	if (keysym == XK_f)
		data->map.extra_z-=1;
	//
	if (keysym == XK_x)
	{
		data->map.line_width = LINE_WIDTH;
		data->map.line_height = LINE_HEIGHT;
		data->map.extra_width = EXTRA_WIDTH;
		data->map.extra_height = EXTRA_HEIGHT;
		data->map.extra_z = EXTRA_Z;
		data->map.extra_angle = EXTRA_ANGLE;
		data->map.extra_vertical_angle = EXTRA_ANGLE;
		data->map.extra_color = EXTRA_COLOR;
	}
	if (keysym == XK_v && data->map.extra_color < 220)
		data->map.extra_color += 2;
	if (keysym == XK_c && data->map.extra_color > 0)
		data->map.extra_color -= 2;

	
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	return (0);
}

int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	ft_printf("Window closed\n");
	return (0);
}