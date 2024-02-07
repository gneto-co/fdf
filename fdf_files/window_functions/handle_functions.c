/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:06:48 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/07 12:36:55 by gneto-co         ###   ########.fr       */
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
	if (keysym == XK_Up)
	{
		data->map.line_width ++;
		data->map.line_height ++;
	}
	if (keysym == XK_Down && data->map.line_width > 0)
	{
		data->map.line_width --;
		data->map.line_height --;
	}
	if (keysym == XK_w)
		data->map.extra_height+=2;
	if (keysym == XK_s)
		data->map.extra_height-=2;
	if (keysym == XK_a)
		data->map.extra_width+=2;
	if (keysym == XK_d)
		data->map.extra_width-=2;
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