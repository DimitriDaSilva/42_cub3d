/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remainder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 07:41:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/23 07:41:33 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_remainder(double numer, double denom)
{
	if (numer < 0)
		numer *= -1;
	return (numer - (denom * (long long)(numer / denom)));
}
