/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 03:45:28 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 03:45:43 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	safe_atoi(const char *str, int *out)
{
	long	result;
	int 	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!is_valid_number(str))
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ((str[i]) >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
			return (0);
		i++;
	}
	*out = ((int)result) * sign;
	return (1);
}
