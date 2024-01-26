/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:24:00 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/26 15:56:55 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	render_rect(t_data *data, t_rect rect)
{
	t_index	i;

	if (!data->win_ptr)
		return (1);
	i.y = rect.y;
	while (i.y < rect.y + rect.height)
	{
		i.x = rect.x;
		while (i.x < rect.x + rect.width)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, i.x, i.y, rect.color);
			i.x++;
		}
		i.y++;
	}
	return (0);
}
