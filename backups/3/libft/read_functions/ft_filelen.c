/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:23:24 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/19 14:31:44 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_filelen(char *file_name)
{
	int i;
	int fd;
	char *str;

	fd = open(file_name, O_RDONLY);

	i = 0;
	while ((str = get_next_line(fd)))
	{
		free(str);
		i++;
	}
	close(fd);
	return (i);
}
