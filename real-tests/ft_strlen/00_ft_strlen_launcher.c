/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_strlen_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 23:01:58 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 02:10:39 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

extern int	ft_strlen_basic_test(void);
extern int	ft_strlen_null_test(void);
extern int	ft_strlen_empty_test(void);
extern int	ft_strlen_newline_test(void);

int	ft_strlen_tests_launcher(void)
{
	t_unit_test	*testlist;
	int			ret;

	testlist = malloc(5 * sizeof(t_unit_test));
	testlist[0].test = NULL;
	load_test(testlist, "ft_strlen: basic test", &ft_strlen_basic_test);
	load_test(testlist, "ft_strlen: null test", &ft_strlen_null_test);
	load_test(testlist, "ft_strlen: empty test", &ft_strlen_empty_test);
	load_test(testlist, "ft_strlen: newline test", &ft_strlen_newline_test);
	ret = launch_tests(testlist);
	free(testlist);
	return (ret);
}
