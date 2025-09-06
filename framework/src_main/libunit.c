/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:18:03 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/06 16:44:51 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int		print_status(int status);

int	launch_tests(t_unit_test *testlist)
{
	int	i;
	int	pid;
	int	ret;
	int	status;
	int	passed;

	i = 0;
	passed = 0;
	while (testlist[i].test)
	{
		pid = fork();
		if (pid == 0)
		{
			ret = testlist[i].test();
			exit (ret);
		}
		write (1, "TEST: ", 6);
		write(1, testlist[i].name, strlen(testlist[i].name));
		while (wait(&status) > 0)
			;
		passed += !print_status(status);
		i++;
	}
	write (1, "passed ", 7);
	write (1, &"0123456789"[passed], 1);
	write (1, "/", 1);
	write (1, &"0123456789"[i], 1);
	write (1, "\n", 1);
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

static int	print_status(int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			write(1, " [SEGV]\n", 8);
		if (WTERMSIG(status) == SIGBUS)
			write(1, " [BUS]\n", 7);
	}
	else
	{
		if (WEXITSTATUS(status) == 0)
		{
			write(1, " [OK]\n", 6);
			return (0);
		}
		else
			write(1, " [FAIL]\n", 8);
	}
	return (1);
}
