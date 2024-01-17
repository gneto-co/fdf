/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:11 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/16 12:06:32 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char *file)
{
	// put the file information on the matrix
	
	// somehow, use matrix to generate 3d map
	
}

void	ft_get_file_informations(char *file)
{
	int		fd;
	char	*file_line;
	char	**line_inf;
	int		**matrix;
	int		i;

	fd = open(file, O_RDONLY);
	if (!fd)
	{
		close(fd);
		return (-1);
	}

	// abrir o ficheiro, contar as linhas
	// malloc matriz com o numero de linhas
	// fechar o ficheiro
	
	// abrir o ficheiro de novo 
	// colocar a informação na matriz
	// fechar o ficheiro


	while (file_line = get_next_line(fd))
	{
		line_inf = ft_split(file_line, ' ');
		i = 0;
		while (line_inf[i])
		{
			
			i++;
		}
		ft_free_split(line_inf, i);
	}
	close(fd);
}
