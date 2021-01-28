/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:31:59 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/24 20:42:17 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long n)
{
	char	*str;
	size_t	size_nbr;

	size_nbr = get_size_lg(n);
	if (!(str = malloc((size_nbr + 1) * sizeof(char))))
		return (0);
	str += size_nbr;
	*str-- = '\0';
	while (size_nbr--)
	{
		*str-- = ft_abs_lg(n) % 10 + ASCII_OFFSET_NUM;
		if (-10 < n && n < 0)
		{
			*str-- = '-';
			break ;
		}
		n /= 10;
	}
	return (++str);
}
