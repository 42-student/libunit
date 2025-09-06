/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:18:03 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/06 15:34:09 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

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
