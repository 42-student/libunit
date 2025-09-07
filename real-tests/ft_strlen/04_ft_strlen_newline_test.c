/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ft_strlen_newline_test.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 23:37:22 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 02:10:19 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	ft_strlen_newline_test(void)
{
	if (ft_strlen("miau\nmiau") == 9)
		return (0);
	return (-1);
}
