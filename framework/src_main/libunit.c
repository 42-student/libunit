/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:18:03 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/07 15:26:03 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	print_status(int status);
static void	print_result(int passed, int total);
static void	exit_timeout(int sig);

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
			signal(SIGALRM, &exit_timeout);
			alarm(TIMEOUT_SEC);
			ret = testlist[i].test();
			exit(ret);
		}
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
			write(1, RED " [SEGV] >>> Segfault\n" RESET, 30);
		if (WTERMSIG(status) == SIGBUS)
			write(1, RED " [BUS] >>> Bus error\n" RESET, 30);
		if (WTERMSIG(status) == SIGABRT)
			write(1, RED " [ABRT] >>> Abort signal\n" RESET, 34);
		if (WTERMSIG(status) == SIGFPE)
			write(1, RED " [FPE] >>> Arithmetic error\n" RESET, 37);
		if (WTERMSIG(status) == SIGPIPE)
			write(1, RED " [PIPE] >>> Pipe error\n" RESET, 32);
		if (WTERMSIG(status) == SIGILL)
			write(1, RED " [ILL] >>>  Illegal operation\n" RESET, 39);
	}
	else
	{
		if (WEXITSTATUS(status) == 0)
		{
			write(1, GREEN " [OK]\n" RESET, 15);
			return (0);
		}
		if (WEXITSTATUS(status) == 124)
			write(1, RED " [TIMEOUT]\n" RESET, 20);
		else
			write(1, RED " [KO]\n" RESET, 15);
	}
	return (1);
}

static void	print_result(int passed, int total)
{
	write(1, "passed ", 7);
	ft_putnbr_fd(passed, 1);
	write(1, "/", 1);
	ft_putnbr_fd(total, 1);
	if (passed == total)
		write(1, GREEN " [OK]\n" RESET, 15);
	else
		write(1, RED " [KO]\n" RESET, 15);
	write(1, "\n", 1);
}

static void	exit_timeout(int sig)
{
	(void)sig;
	exit(124);
}
