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

int	main(void)
{
	int	nbr_of_tests;
	int	passed;

	nbr_of_tests = 1;
	passed = basic_tests_launcher();
	if (passed == nbr_of_tests)
		write(1, GREEN"All tests passed!\n\n"RESET, 28);
	return (0);
}
