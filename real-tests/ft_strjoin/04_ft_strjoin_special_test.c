/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ft_strjoin_special_test.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:58:12 by smargine          #+#    #+#             */
/*   Updated: 2025/09/07 01:01:33 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	ft_strjoin_special_test(void)
{
	char	*result;

	result = ft_strjoin("!@#$ ", "{[-_-]}");
	if (ft_strcmp(result, "!@#$ {[-_-]}") == 0)
	{
		free(result);
		return (0);
	}
	else
	{
		free(result);
		return (-1);
	}
}
