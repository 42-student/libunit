/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_ft_strncmp_minus_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:02:45 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 01:51:54 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	ft_strncmp_minus_test(void)
{
	if (ft_strncmp("aaaa", "aaab", 42) == -1)
		return (0);
	return (-1);
}
