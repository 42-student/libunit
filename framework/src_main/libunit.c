/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:18:03 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/07 15:56:58 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	exit_timeout(int sig);
static void	child(t_unit_test *testlist, int i);

int	launch_tests(t_unit_test *testlist)
{
	int	i;
	int	pid;
	int	status;
	int	passed;

	i = 0;
	passed = 0;
	while (testlist[i].test)
	{
		pid = fork();
		if (pid == 0)
			child(testlist, i);
		write(1, testlist[i].name, ft_strlen(testlist[i].name));
		while (wait(&status) > 0)
			;
		passed += !print_status(status);
		i++;
	}
	print_result(passed, i);
	return (passed == i);
}

void	load_test(t_unit_test *testlist, char *name, void *test)
{
	int		i;

	i = 0;
	while (testlist[i].test)
		i++;
	testlist[i].name = name;
	testlist[i].test = test;
	testlist[i + 1].test = NULL;
	return ;
}

static void	child(t_unit_test *testlist, int i)
{
	int	ret;

	signal(SIGALRM, &exit_timeout);
	alarm(TIMEOUT_SEC);
	ret = testlist[i].test();
	exit (ret);
}

static void	exit_timeout(int sig)
{
	(void)sig;
	exit(124);
}
