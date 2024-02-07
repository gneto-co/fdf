/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:01:08 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/07 17:39:18 by gneto-co         ###   ########.fr       */
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
	int		z_max;
	int		z_min;
	int		line_width;
	int		line_height;
	int		extra_width;
	int		extra_height;
	int		extra_angle;
	int		extra_z;
}			t_map;

void		fdf(char *file);
t_map		get_file_coordinates(char *file_name, int y_max);
void		free_matrix(int **matrix, int matrix_len);

/* *********************************** */
/*                                     */
/*           WINDOW_FUNCTIONS          */
/*                                     */
/* *********************************** */

// window parameters
// -window
# define WINDOW_WIDTH 1900
# define WINDOW_HEIGHT 900
# define W_WIDTH_CENTER (WINDOW_WIDTH / 2)
# define W_HEIGHT_CENTER (WINDOW_HEIGHT / 2)
// -margin
# define MARGIN_WIDTH (WINDOW_WIDTH * 0.05)
# define MARGIN_HEIGHT (WINDOW_WIDTH * 0.05)
// -text area
# define TEXT_WIDTH_START (MARGIN_WIDTH)
# define TEXT_WIDTH (WINDOW_WIDTH * 0.20)
# define TEXT_HEIGHT_START (MARGIN_HEIGHT)
# define TEXT_HEIGHT (WINDOW_HEIGHT * 0.80)
// -draw area
# define DRAW_WIDTH_START (MARGIN_WIDTH * 2 + TEXT_WIDTH)
# define DRAW_WIDTH (WINDOW_WIDTH * 0.65)
# define DRAW_HEIGHT_START (MARGIN_HEIGHT)
# define DRAW_HEIGHT (WINDOW_HEIGHT * 0.80)
// -figure
# define  LINE_WIDTH 90
# define LINE_HEIGHT 90
// -others
# define WINDOW_NAME "fdf"
# define MLX_ERROR 1
//
//
// colors
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define UPPER_COLOR RED_PIXEL
# define BOTTOM_COLOR BLUE_PIXEL
# define BORDERS_COLOR 0x1080FF
# define COLOR_MAX 130
# define COLOR_MIN 30
// pi
# define M_PI 3.14159265358979323846

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
	int		z0;
	int		z1;
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
void		draw_map(t_data *data);

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
void		render_p_line(t_data *data, t_line line);
void		render_line(t_data *data, t_line line);

// mlx_utils
void		img_pix_put(t_img *img, int x, int y, int color);
int			ft_rgb_to_int(int red, int green, int blue);

// line tests
int			line_1(t_data *data);
int			line_2(t_data *data);
int			line_3(t_data *data);
int			line_4(t_data *data);
void		draw_area(t_data *data, t_rect sqr);

/* *********************************** */
/*                                     */
/*                 END                 */
/*                                     */
/* *********************************** */

#endif
