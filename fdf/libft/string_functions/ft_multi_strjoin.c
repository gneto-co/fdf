/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:39:11 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/12 17:23:35 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*sort(char *str, char c, va_list args)
{
	char	*new_str;
	char	*num;

	if (c == 'd')
	{
		num = ft_itoa(va_arg(args, int));
		new_str = ft_strjoin(str, num);
		free(num);
	}
	else if (c == 's')
		new_str = ft_strjoin(str, va_arg(args, char *));
	else if (c == 'c')
		new_str = ft_str_char_join(str, va_arg(args, int));
	else
		return (NULL);
	return (new_str);
}

char	*ft_multi_strjoin(const char *source, ...)
{
	va_list	args;
	char	*str;
	char	*temp;

	va_start(args, source);
	if (!source)
		return (NULL);
	str = ft_strdup("");
	while (*source)
	{
		if (*source == '%')
		{
			source++;
			temp = str;
			str = sort(str, *source, args);
			if (temp != str)
				free(temp);
		}
		else
		{
			temp = str;
			str = ft_str_char_join(str, *source);
			if (temp != str)
				free(temp);
		}
		source++;
	}
	va_end(args);
	return (str);
}
