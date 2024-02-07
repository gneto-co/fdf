/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:06:48 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/07 23:14:09 by gneto-co         ###   ########.fr       */
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
	//
	if (keysym == XK_Left)
	{
		data->map.extra_z += 0.5;
		data->map.line_width ++;
		data->map.line_height ++;
	}
	if (keysym == XK_Right && data->map.line_width > 0)
	{
		// data->map.extra_z -= 0.2;
		data->map.line_width --;
		data->map.line_height --;
	}
	//
	if (keysym == XK_Up)
		data->map.extra_angle+=5;
	if (keysym == XK_Down)
		data->map.extra_angle-=5;
	//
	if (keysym == XK_w)
		data->map.extra_height+=5;
	if (keysym == XK_s)
		data->map.extra_height-=5;
	if (keysym == XK_a)
		data->map.extra_width+=5;
	if (keysym == XK_d)
		data->map.extra_width-=5;
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
	}
	if (keysym == XK_v && data->map.extra_color < 255)
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