/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 23:05:03 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 00:36:39 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	ft_strlen_tests_launcher();
	ft_strcmp_tests_launcher();
	ft_isdigit_tests_launcher();
	ft_strjoin_tests_launcher();
	return (0);
}
