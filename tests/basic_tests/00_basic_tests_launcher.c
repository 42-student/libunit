/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_basic_tests_launcher.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:38:10 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 14:38:14 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"
#include "libunit.h"

int	basic_tests_launcher(void)
{
	t_unit_test	testlist[10];
	int			ret;

	testlist[0].test = NULL;
	load_test(testlist, "Basic Test: OK test", &ok_test);
	load_test(testlist, "Basic Test: KO test", &ko_test);
	load_test(testlist, "Basic Test: SIGSEGV test", &segv_test);
	load_test(testlist, "Basic Test: SIGBUS test", &buserr_test);
	load_test(testlist, "Basic Test: SIGABRT test", &sigabrt_test);
	load_test(testlist, "Basic Test: SIGFPE test", &sigfpe_test);
	load_test(testlist, "Basic Test: SIGPIPE test", &sigpipe_test);
	load_test(testlist, "Basic Test: SIGILL test", &illegal_test);
	load_test(testlist, "Basic Test: timeout test", &timeout_test);
	ret = launch_tests(testlist);
	return (ret);
}
