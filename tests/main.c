/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:57:05 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 14:26:44 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"

void	print_banner(void)
{
	const char	*banner = " _     _  ____  _     _      _ _____ \n"
		"/ \\   / \\/  _ \\/ \\ /\\/ \\  /|/ Y__ __\\\n"
		"| |   | || | //| | ||| |\\ ||| | / \\  \n"
		"| |_/\\| || |_\\| \\_/|| | \\||| | | |  \n"
		"\\____/\\_/\\____/\\____/\\_/  \\|\\_/ \\_/  \n";

	ft_printf("%s", banner);
}

int	main(void)
{
	int	nbr_of_tests;
	int	passed;
	print_banner();
	nbr_of_tests = 1;
	passed = basic_tests_launcher();
	if (passed == nbr_of_tests)
		write(1, GREEN"All tests passed!\n\n"RESET, 28);
	return (0);
}
