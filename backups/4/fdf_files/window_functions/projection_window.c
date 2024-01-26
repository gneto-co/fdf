/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:09:59 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/26 15:19:46 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#define WINDOW_WIDTH 1900
#define WINDOW_HEIGHT 1000
#define WINDOW_NAME "fdf"
#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define DARK_RED_PIXEL 0xC93030
#define GREEN_PIXEL 0xFF00
#define DARK_GREEN_PIXEL 0x34D034
#define WHITE_PIXEL 0xFFFFFF

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

typedef struct s_index
{
	int		x;
	int		y;
}			t_index;

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

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

int	render(t_data *data)
{
	/* if window has been destroyed, we don't want to put the pixel ! */
	render_rect(data, (t_rect){0, WINDOW_HEIGHT / 4, WINDOW_WIDTH, 1,
		WHITE_PIXEL});
	render_rect(data, (t_rect){0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, 1,
		GREEN_PIXEL});
	render_rect(data, (t_rect){0, (WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 4), WINDOW_WIDTH, 1,
		WHITE_PIXEL});

	render_rect(data, (t_rect){WINDOW_WIDTH / 4, 0, 1, WINDOW_HEIGHT,
		WHITE_PIXEL});
	render_rect(data, (t_rect){WINDOW_WIDTH / 2, 0, 1, WINDOW_HEIGHT,
		RED_PIXEL});
	render_rect(data, (t_rect){(WINDOW_WIDTH / 2 + WINDOW_WIDTH / 4), 0, 1, WINDOW_HEIGHT,
		WHITE_PIXEL});

    // render_rect(data, (t_rect){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
	// 	WHITE_PIXEL});
	return (0);
}

int	projection_window(int **matrix)
{
	t_data	data;

	/* initialize mlx and open window */
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_NAME);
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	/* Setup hooks */
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
