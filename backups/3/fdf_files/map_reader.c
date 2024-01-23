/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:11 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/19 15:58:36 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(int **matrix, int matrix_len)
{
	int	i;

	i = 0;
	while (i < matrix_len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static int	*line_to_vector(char *line)
{
	int		*vector;
	int		i;
	char	**str;

	str = ft_split(line, ' ');
	vector = malloc(sizeof(int) * ft_arraylen(str));
	i = 0;
	while (str[i])
	{
		vector[i] = atoi(str[i]);
		i++;
	}
	ft_free_array(str);
	return (vector);
}

int	**get_file_coordinates(char *file_name, int y_max)
{
	int **matrix;
	int fd;
	int i;
	char *str;

	i = 0;
	fd = open(file_name, O_RDONLY);
	matrix = malloc(sizeof(int *) * y_max);
	while ((str = get_next_line(fd)))
	{
		matrix[i] = line_to_vector(str);
		free(str);
		i++;
	}
	close(fd);
	return (matrix);
}
