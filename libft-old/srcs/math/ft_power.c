/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:12:01 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/17 11:01:36 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int power)
{
	int result;

	if (power == 0)
		return (1);
	else if (power <= 0)
		return (0);
	result = 1;
	while (power--)
		result *= nb;
	return (result);
}
