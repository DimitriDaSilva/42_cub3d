/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:44:56 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/01 23:18:34 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_max(long long nb, int length)
{
	int	check;

	check = 0;
	if (length >= 18 && nb >= 922337203685477580)
		check = 1;
	else if (length >= 18 && nb <= -922337203685477580)
		check = 1;
	return (check);
}

long long	ft_atoi(const char *str)
{
	long long	number;
	int			sign;
	int			length;

	number = 0;
	sign = 1;
	length = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
	{
		if (is_max(number, length))
			return (0);
		number *= 10;
		number += (int)(*str - '0');
		str++;
		length++;
	}
	return (sign * number);
}
