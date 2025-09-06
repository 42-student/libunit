/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:30:07 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/06 19:30:43 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H 
# define LIBUNIT_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include "color.h"

typedef struct s_unit_test
{
	int		(*test)(void);
	char	*name;
}	t_unit_test;

int		strlen_launcher(void);
int		launch_tests(t_unit_test *testlist);
void	load_test(t_unit_test *testlist, char *name, void *test);

#endif
