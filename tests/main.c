/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:57:05 by smargine          #+#    #+#             */
/*   Updated: 2025/09/06 19:22:43 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"

int	main(int argc, char **argv)
{
	int		ret;

	(void) argc;
	(void) argv;
	ret = basic_tests_launcher();
	return (ret);
}
