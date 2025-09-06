/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:12:55 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/06 12:56:46 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"
#include "libunit.h"

int	basic_test(void)
{
	int	a;

	a = strlen("test");
	printf(">>> BASIC <<<\n");
	if (a == 4)
		return (0);
	else
		return (-1);
}
