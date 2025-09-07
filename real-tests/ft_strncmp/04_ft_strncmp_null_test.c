/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ft_strncmp_null_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:08:07 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 01:51:14 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	ft_strncmp_null_test(void)
{
	if (ft_strncmp("42Berlin", NULL, 42) == -42)
		return (0);
	return (-1);
}
