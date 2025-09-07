/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:18:03 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/07 12:45:52 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	print_status(int status);
static void	print_result(int passed, int total);

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
		write(1, testlist[i].name, ft_strlen(testlist[i].name));
		while (wait(&status) > 0)
			;
		passed += !print_status(status);
		i++;
	}
	print_result(passed, i);
	return (0);
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

static int	print_status(int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			write(1, RED" [SEGV]\n"RESET, 17);
		if (WTERMSIG(status) == SIGBUS)
			write(1, RED" [BUS]\n"RESET, 16);
		if (WTERMSIG(status) == SIGABRT)
			write(1, RED" [ABRT]\n"RESET, 17);
		if (WTERMSIG(status) == SIGFPE)
			write(1, RED" [FPE] (Arithmetic error!)\n"RESET, 36);
	}
	else
	{
		if (WEXITSTATUS(status) == 0)
		{
			write(1, GREEN" [OK]\n"RESET, 15);
			return (0);
		}
		else
			write(1, RED" [KO]\n"RESET, 15);
	}
	return (1);
}

static void	print_result(int passed, int total)
{
	char	*num;

	write(1, "passed ", 7);
	num = ft_itoa(passed);
	if (num)
		write(1, num, ft_strlen(num));
	write(1, "/", 1);
	free(num);
	num = ft_itoa(total);
	if (num)
		write(1, num, ft_strlen(num));
	if (passed == total)
		write(1, GREEN" [OK]\nAll tests passed!\n"RESET, 33);
	else
		write(1, RED" [KO]\n"RESET, 15);
	free(num);
}
