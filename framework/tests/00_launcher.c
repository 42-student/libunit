/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:32:13 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/06 13:22:57 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"
#include "libunit.h"

int		launch_tests(t_unit_test *testlist);
void	load_test(t_unit_test *testlist, char *name, void *test);

int	strlen_launcher(void)
{
	t_unit_test	*testlist;
	int			ret;

	testlist = malloc(100 * sizeof(t_unit_test));
	testlist[0].test = NULL;
	load_test(testlist, "Basic test", &basic_test);
	load_test(testlist, "NULL test", &null_test);
	/*l0oad_test(&testlist, "Bigger string test", &bigger_str_test);
	This test won't be loaded */
	ret = launch_tests(testlist);
	free(testlist);
	return (ret);
}

int	launch_tests(t_unit_test *testlist)
{
	int	i;
	int	pid;
	int	ret;
	int	status;

	i = 0;
	while (testlist[i].test)
	{
		pid = fork();
		if (pid == 0)
		{
			ret = testlist[i].test();
			exit (ret);
		}
		printf("testing: %s\n", testlist[i].name);
		while (wait(&status) > 0)
			;
		printf("status: %i:\n\n", WEXITSTATUS(status));
		i++;
	}
	return (0);
}

void	load_test(t_unit_test *testlist, char *name, void *test)
{
	int	i;

	i = 0;
	while (testlist[i].test)
		i++;
	testlist[i].name = name;
	testlist[i].test = test;
	testlist[i + 1].test = NULL;
	return ;
}
