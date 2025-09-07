/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ft_strncmp_plus_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 23:59:49 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 01:52:02 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	ft_strncmp_plus_test(void)
{
	if (ft_strncmp("aaab", "aaaa", 42) == 1)
		return (0);
	return (-1);
}
