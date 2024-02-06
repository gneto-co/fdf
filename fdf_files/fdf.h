/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:01:08 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/06 00:47:56 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* *********************************** */
/*                                     */
/*             FDF HEADER              */
/*                                     */
/* *********************************** */

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_map
{
	int		**matrix;
	int		x_max;
	int		y_max;
	int		line_width;
	int		line_height;
}			t_map;

void		fdf(char *file);
t_map		get_file_coordinates(char *file_name, int y_max);
void		free_matrix(int **matrix, int matrix_len);

/* *********************************** */
/*                                     */
/*           WINDOW_FUNCTIONS          */
/*                                     */
/* *********************************** */

# define WINDOW_WIDTH 1100
# define WINDOW_HEIGHT 1000
# define W_WIDTH_CENTER (WINDOW_WIDTH / 2)
# define W_HEIGHT_CENTER (WINDOW_HEIGHT / 2)
# define MARGIN_WIDTH 300
# define MARGIN_HEIGHT 300
# define DRAWN_AREA_WIDTH (WINDOW_WIDTH - MARGIN_WIDTH * 2)
# define DRAWN_AREA_HEIGHT (WINDOW_HEIGHT - MARGIN_HEIGHT * 2)
# define WINDOW_NAME "fdf"
# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		cur_img;
	t_img	img;
	t_map	map;
}			t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

typedef struct s_line
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		color;
}			t_line;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}			t_point;

// pw
int			pw(t_map map);
int			render(t_data *data);
void		drawn_map(t_data *data);

// pw_operations
void		setup_image(t_data *data);
void		setup_hooks(t_data *data);
int			initialize_data(t_data *data, t_map map);
void		free_mlx_stuff(t_data *data);

// handle_functions
int			handle_keypress(int keysym, t_data *data);
int			handle_keyrelease(int keysym, void *data);
int			handle_close(t_data *data);

// render funtions
void		render_background(t_img *img, int color);
void		render_rect(t_img *img, t_rect rect);
void		render_line(t_img *img, t_line line);

// mlx_utils
void		img_pix_put(t_img *img, int x, int y, int color);

// line tests
int			line_1(t_data *data);
int			line_2(t_data *data);
int			line_3(t_data *data);
int			line_4(t_data *data);
int			draw_area(t_data *data);

/* *********************************** */
/*                                     */
/*                 END                 */
/*                                     */
/* *********************************** */

#endif
