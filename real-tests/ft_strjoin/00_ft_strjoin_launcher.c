/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_strjoin_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:35:05 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 12:47:49 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

extern int	ft_strjoin_basic_test(void);
extern int	ft_strjoin_empty_test(void);
extern int	ft_strjoin_null_test(void);
extern int	ft_strjoin_special_test(void);

int	ft_strjoin_tests_launcher(void)
{
	t_unit_test	testlist[5];
	int			ret;

	testlist[0].test = NULL;
	load_test(testlist, "ft_strjoin: basic test", &ft_strjoin_basic_test);
	load_test(testlist, "ft_strjoin: empty test", &ft_strjoin_empty_test);
	load_test(testlist, "ft_strjoin: null test", &ft_strjoin_null_test);
	load_test(testlist, "ft_strjoin: special test", &ft_strjoin_special_test);
	ret = launch_tests(testlist);
	return (ret);
}
