/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:16:57 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/21 20:06:13 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_roundf(long double nb, int decimal_places)
{
	double		power;
	long double	ret;

	if (decimal_places <= 0)
		return (0);
	power = ft_power(10, decimal_places - 1);
	nb *= power;
	if (nb >= 0)
		ret = (long long)(nb + 0.5) / power;
	else
		ret = (long long)(nb - 0.5) / power;
	return (ret);
}
