/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:29:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/12 17:01:18 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_files/fdf.h"
#include <stdio.h>

static void	ft_error(void)
{
	ft_putstr("Error\n");
}

int	main(int ac, char *av[])
{
	(void)av;
	(void)ac;
	(void)ft_error;
	char	*str = ft_multi_strjoin("o %s tem %d casa%c", "rui", 3, 's');
	ft_putstr(str);
	free (str);
}
