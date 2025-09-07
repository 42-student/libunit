/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_strncmp_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 23:44:37 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 02:12:19 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

extern int	ft_strncmp_basic_test(void);
extern int	ft_strncmp_plus_test(void);
extern int	ft_strncmp_minus_test(void);
extern int	ft_strncmp_null_test(void);

int	ft_strncmp_tests_launcher(void)
{
	t_unit_test	*testlist;
	int			ret;

	testlist = malloc(5 * sizeof(t_unit_test));
	testlist[0].test = NULL;
	load_test(testlist, "ft_strncmp: basic test", &ft_strncmp_basic_test);
	load_test(testlist, "ft_strncmp: plus test", &ft_strncmp_plus_test);
	load_test(testlist, "ft_strncmp: minus test", &ft_strncmp_minus_test);
	load_test(testlist, "ft_strncmp: null test", &ft_strncmp_null_test);
	ret = launch_tests(testlist);
	free(testlist);
	return (ret);
}
