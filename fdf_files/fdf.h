/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:01:08 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/29 12:20:42 by gneto-co         ###   ########.fr       */
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

typedef struct point_coordinate
{
	int		x;
	int		y;
	int		z;
}			t_point_coordinate;

void		fdf(char *file);
int			**get_file_coordinates(char *file_name, int y_max);
void		free_matrix(int **matrix, int matrix_len);

/* *********************************** */
/*                                     */
/*           WINDOW_FUNCTIONS          */
/*                                     */
/* *********************************** */

# define WINDOW_WIDTH 1900
# define WINDOW_HEIGHT 1000
# define WINDOW_NAME "fdf"
# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF

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
	t_img	img;
	int		cur_img;
}			t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

int			projection_window(int **matrix);

// render funtions
void		render_background(t_img *img, int color);
int			render_rect(t_img *img, t_rect rect);

// mlx_utils
void		img_pix_put(t_img *img, int x, int y, int color);

// line tests
int			line_1(t_data *data);
int			line_2(t_data *data);

/* *********************************** */
/*                                     */
/*                 END                 */
/*                                     */
/* *********************************** */

#endif
