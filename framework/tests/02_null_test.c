/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:12:55 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/06 13:21:38 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"
#include "libunit.h"

int	null_test(void)
{
	int		a;
	char	*test;

	test = NULL;
	a = strlen(test);
	printf(">>> NULL <<<\n");
	return (-1);
}
