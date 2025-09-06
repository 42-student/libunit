/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tests.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:10:04 by mmillhof          #+#    #+#             */
/*   Updated: 2025/09/06 23:46:20 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_TESTS_H
# define BASIC_TESTS_H

# include "libunit.h"

int	basic_tests_launcher(void);
int	ok_test(void);
int	ko_test(void);
int	segv_test(void);
int	buserr_test(void);

#endif
