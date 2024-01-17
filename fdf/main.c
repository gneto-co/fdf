/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:29:13 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/17 14:17:12 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_files/fdf.h"
#include <stdio.h>

/* int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		fdf(av[1]);
	}
} */

int main()
{
	char str1[] = "abc";
	char str2[] = "drf";
	char *s = ft_multi_strjoin("%s%s%s / %d",str1, str2, "cenas", 42);
	ft_putstr(s);
	free(s);
}
