/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_basic_tests_launcher.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:32:13 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/07 00:16:34 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"
#include "libunit.h"

int	basic_tests_launcher(void)
{
	t_unit_test	*testlist;
	int			ret;

	testlist = malloc(5 * sizeof(t_unit_test));
	testlist[0].test = NULL;
	load_test(testlist, "Basic Test: OK test", &ok_test);
	load_test(testlist, "Basic Test: KO test", &ko_test);
	load_test(testlist, "Basic Test: SIGSEGV test", &segv_test);
	load_test(testlist, "Basic Test: SIGBUS test", &buserr_test);
	ret = launch_tests(testlist);
	free(testlist);
	return (ret);
}
