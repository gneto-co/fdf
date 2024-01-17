/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:29:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/14 00:34:04 by gneto-co         ###   ########.fr       */
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
	char	*str;

	(void)av;
	(void)ac;
	(void)ft_error;
	str = ft_multi_strjoin("%c%c %s %d %d%d",
	'e',
	'u',
	"vou escrever",
	1,2,3
	);
	ft_putstr(str);

	ft_printf("\n\n%s %s nº%d"
	,"hello"
	,"world"
	,2
	);
	free(str);
}
