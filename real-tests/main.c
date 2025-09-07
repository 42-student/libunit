/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 23:05:03 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 14:26:56 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "real_tests.h"

void	print_banner(void)
{
	const char	*banner;

	banner = " /$$       /$$ /$$       /$$   /$$\n"
		"		/ $$ /\n"
		"		$$    \n"
		"| $$      |__/| $$      | $$  | $$          |__/  | $$    \n"
		"| $$       /$$| $$$$$$$ | $$  | $$ /$$$$$$$  /$$\n"
		"		/ $$$$$$  \n"
		"| $$      | $$| $$__  $$| $$  | $$| $$__  $$| $$|_  $$_/  \n"
		"| $$      | $$| $$  \\ $$| $$  | $$| $$  \\ $$| $$  | $$    \n"
		"| $$      | $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$ / $$\n"
		"| $$$$$$$$| $$| $$$$$$$/|  $$$$$$/| $$  | $$| $$  |  $$$$/\n"
		"|________/|__/|_______/  \\______/ |__/  |__/|__/   \\___/  \n"
		"                                                          \n"
		"                                                          \n";
	ft_printf("%s\n", banner);
}

int	main(void)
{
	int	nbr_of_tests;
	int	passed;

	print_banner();
	nbr_of_tests = 4;
	passed = 0;
	passed += ft_strlen_tests_launcher();
	passed += ft_strncmp_tests_launcher();
	passed += ft_isdigit_tests_launcher();
	passed += ft_strjoin_tests_launcher();
	if (passed == nbr_of_tests)
		write(1, GREEN "All tests passed!\n\n" RESET, 28);
	return (0);
}
