/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:30:07 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/07 15:23:15 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H 
# define LIBUNIT_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "color.h"

# define TIMEOUT_SEC 5

typedef struct s_unit_test
{
	int		(*test)(void);
	char	*name;
}	t_unit_test;

int		strlen_launcher(void);
int		launch_tests(t_unit_test *testlist);
void	load_test(t_unit_test *testlist, char *name, void *test);

#endif
