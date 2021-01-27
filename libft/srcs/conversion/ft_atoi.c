/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:44:56 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/12 18:14:19 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int number;
	int sign;
	int length;

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
		if (++length > 10 && sign == -1)
			return (0);
		else if (length > 10 && sign == 1)
			return (-1);
		number *= 10;
		number += (int)(*str - '0');
		str++;
	}
	return (sign * number);
}
