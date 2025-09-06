/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_isdigit_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:15:31 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 00:30:01 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

extern int	ft_isdigit_basic_test(void);
extern int	ft_isdigit_char_test(void);
extern int	ft_isdigit_null_test(void);
extern int	ft_isdigit_space_test(void);

int	ft_isdigit_tests_launcher(void)
{
	t_unit_test	*testlist;
	int			ret;

	testlist = malloc(5 * sizeof(t_unit_test));
	testlist[0].test = NULL;
	load_test(testlist, "ft_isdigit Test: basic test", &ft_isdigit_basic_test);
	load_test(testlist, "ft_isdigit Test: char test", &ft_isdigit_char_test);
	load_test(testlist, "ft_isdigit Test: null test", &ft_isdigit_null_test);
	load_test(testlist, "ft_isdigit Test: space test", &ft_isdigit_space_test);
	ret = launch_tests(testlist);
	free(testlist);
	return (ret);
}
