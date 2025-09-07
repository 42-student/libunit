/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_strncmp_basic_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 23:48:42 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 02:11:27 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	ft_strncmp_basic_test(void)
{
	if (ft_strncmp("abc", "abc", 42) == 0)
		return (0);
	return (-1);
}
