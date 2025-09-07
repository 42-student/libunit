/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:18:03 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/07 15:56:16 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	print_status(int status)
{
	if (WIFSIGNALED(status))
		print_signals(status);
	else
	{
		if (WEXITSTATUS(status) == 0)
		{
			write(1, GREEN" [OK]\n"RESET, 15);
			return (0);
		}
		if (WEXITSTATUS(status) == 124)
			write(1, RED" [TIMEOUT]\n"RESET, 20);
		else
			write(1, RED" [KO]\n"RESET, 15);
	}
	return (1);
}

void	print_result(int passed, int total)
{
	write(1, "passed ", 7);
	ft_putnbr_fd(passed, 1);
	write(1, "/", 1);
	ft_putnbr_fd(total, 1);
	if (passed == total)
		write(1, GREEN" [OK]\n"RESET, 15);
	else
		write(1, RED" [KO]\n"RESET, 15);
	write (1, "\n", 1);
}

void	print_signals(int status)
{
	if (WTERMSIG(status) == SIGSEGV)
		write(1, RED" [SEGV] >>> Segfault\n"RESET, 30);
	if (WTERMSIG(status) == SIGBUS)
		write(1, RED" [BUS] >>> Bus error\n"RESET, 30);
	if (WTERMSIG(status) == SIGABRT)
		write(1, RED" [ABRT] >>> Abort signal\n"RESET, 34);
	if (WTERMSIG(status) == SIGFPE)
		write(1, RED" [FPE] >>> Arithmetic error\n"RESET, 37);
	if (WTERMSIG(status) == SIGPIPE)
		write(1, RED" [PIPE] >>> Pipe error\n"RESET, 32);
	if (WTERMSIG(status) == SIGILL)
		write(1, RED" [ILL] >>>  Illegal operation\n"RESET, 39);
}
