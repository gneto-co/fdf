/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:11 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/02 11:48:51 by gneto-co         ###   ########.fr       */
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

static int	*line_to_vector(char *line, t_map *map)
{
	int		*vector;
	int		i;
	char	**str;

	str = ft_split(line, ' ');
	vector = malloc(sizeof(int) * (ft_arraylen(str)));
	i = 0;
	while (str[i])
	{
		vector[i] = atoi(str[i]);
		i++;
	}
	map->x_max = i;
	ft_free_array(str);
	return (vector);
}

t_map	get_file_coordinates(char *file_name, int y_max)
{
	t_map	map;
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (!fd)
		return ((t_map){NULL, -1, -1});
	map.matrix = malloc(sizeof(int *) * y_max);
	while ((str = get_next_line(fd)))
	{
		map.matrix[i] = line_to_vector(str, &map);
		free(str);
		i++;
	}
	map.y_max = i;
	close(fd);
	return (map);
}

/* t_point *get_file_coordinates(char *file_name, int file_len)
{
	t_point *p;

	int		fd;
	int		i;
	int		y;
	int		x;
	char	*line;
	char	**str;

	fd = open(file_name, O_RDONLY);
	if (!fd)
		return (NULL);
	p = malloc(sizeof(t_point) * (file_len + 1));

	i = 0;
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str = ft_split(line, ' ');

		x = 0;
		while (str[x])
		{
			p[i++] = (t_point){x, y, ft_atoi(str[x])};
			x++;
		}
		ft_free_array(str);
		free(line);
		y++;
	}
	p[i] = (t_point){-1, -1, -1};

	close(fd);
	return(p);
} */