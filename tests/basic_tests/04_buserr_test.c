/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_buserr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:44:02 by smargine          #+#    #+#             */
/*   Updated: 2025/09/06 17:40:11 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"
#include "libunit.h"

#define ENABLE_MEMALIGN	"pushf\norl $0x40000,(%rsp)\npopf"

int	buserr_test(void)
{
	char	*p;
	int		*i;

	__asm__(ENABLE_MEMALIGN);
	p = malloc(sizeof(int) + 1);
	i = (int *)(++p);
	*i = 0;
	if (*p)
		return (0);
	return (-1);
}

// int buserr_test(void)
// {
// 	char p[4];
// 	int *a;
// 	a = (int *)(p + 1);
// 	*a = 42;
// 	if (*a == 42)
// 		return (0);
// 	return (-1);
// }
