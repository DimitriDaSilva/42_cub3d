/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:31:59 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/18 19:44:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(unsigned long long n)
{
	char	*str;
	size_t	size_nbr;

	size_nbr = get_len_uint(n);
	if (!(str = ft_calloc(size_nbr + 1, sizeof(char))))
		return (0);
	str += size_nbr - 1;
	while (size_nbr--)
	{
		*str-- = n % 10 + ASCII_OFFSET_NUM;
		n /= 10;
	}
	return (++str);
}
