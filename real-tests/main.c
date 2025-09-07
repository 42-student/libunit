/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 23:05:03 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 02:20:36 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	ft_strlen_tests_launcher();
	write(1, "\n", 1);
	ft_strncmp_tests_launcher();
	write(1, "\n", 1);
	ft_isdigit_tests_launcher();
	write(1, "\n", 1);
	ft_strjoin_tests_launcher();
	write(1, "\n", 1);
	return (0);
}
