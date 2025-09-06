/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:32:13 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/06 15:32:07 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"
#include "libunit.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;
	int			ret;

	testlist = malloc(5 * sizeof(t_unit_test));
	testlist[0].test = NULL;
	load_test(testlist, "Basic test", &basic_test);
	load_test(testlist, "NULL test", &null_test);
	/*l0oad_test(&testlist, "Bigger string test", &bigger_str_test);
	This test won't be loaded */
	ret = launch_tests(testlist);
	free(testlist);
	return (ret);
}
