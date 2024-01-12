/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:27:56 by gneto-co          #+#    #+#             */
/*   Updated: 2024/01/12 18:49:10 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

// run that in your file
// cc .menu/* -o .menu_exe && ./.menu_exe

char		g_name[] = "fdf";

#pragma region ex_

static void	ex_1(void)
{
	char	*str;
	int		j;

	j = 0;
	str = ft_multi_strjoin(" ./%s", g_name);
	system(str);
	free(str);
}
static void	ex_2(void)
{
	char	*str;

	str = ft_multi_strjoin("./%s", g_name);
	system(str);
	free(str);
}

static void	ex_3(void)
{
	system("make re");
}

static void	ex_4(void)
{
	system("make fclean");
}

static void	ex_5(void)
{
	return ;
}

static void	ex_g(void)
{
    char    g1[] = "git add ../*";
    char    g2[] = "git commit -m \"menu_commit\"";
    char    g3[] = "git push";
    char    g4[] = "git log";
    char    *order;
    
	order = ft_multi_strjoin("%s && %s && %s && %s",g1, g2, g3, g4);
    system(order);
	free(order);
}

static void	ex_n(void)
{
	system("clear");
	printf("\033[34mnorminette test (only errors): \033[0m\n");
	system("find . -type f \\( -name '*.c' -o -name '*.h' \\) ! -name 'menu.c' -exec norminette {} \\; | grep -E 'Error|Warning'");
}

static void	ex_r(void)
{
	system("cc .menu/* -o .menu_exe && ./.menu_exe");
	exit(0);
}

static void	ex_q(void)
{
	system("rm .menu_exe");
	system("clear");
	exit(0);
}
#pragma endregion

static char	main_menu()
{
	char	c;
	
	fflush(stdout);
	printf("\033]0;Test Menu\007");
	printf("\nExecute:\n"
			"\n\033[93m 1\x1b[0m ./fdf"
			"\n\033[93m 2\x1b[0m valgrind ./fdf"
			"\n\033[32m 3\x1b[0m make re"
			"\n\033[32m 4\x1b[0m make fclean"
			"\n ---------"
			"\n\033[34m g\x1b[0m git commit"
			"\n\033[35m n\x1b[0m norminette"
			"\n\x1b[31m r\x1b[0m to reload"
			"\n\x1b[31m q\x1b[0m to quit"
			"\n\n> ");
	scanf(" %c", &c);
	return (c);
}

static void	sort_number(char c)
{
	if (c == '1')
		ex_1();
	else if (c == '2')
		ex_2();
	else if (c == '3')
		ex_3();
	else if (c == '4')
		ex_4();
	else if (c == 'g')
		ex_g();
	else if (c == 'n')
		ex_n();
	else if (c == 'r')
		ex_r();
	else if (c == 'q')
		ex_q();
}
int	main(void)
{
	char	c;

	c = 0;
	system("clear");
	while (c != 'q')
	{
		c = main_menu();
		system("clear");
		sort_number(c);
	}
}
