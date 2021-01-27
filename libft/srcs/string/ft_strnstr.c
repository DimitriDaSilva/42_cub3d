/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:33:52 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/16 19:11:22 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*sav_big;
	char	*sav_little;

	if (!len)
		return (0);
	if (!(*little))
		return ((char *)big);
	while (*big)
	{
		sav_big = (char *)big;
		sav_little = (char *)little;
		while (len-- != 0 && *big++ == *little++)
		{
			if (*little == '\0')
				return (sav_big);
		}
		if (len == 0)
			return (0);
		little = sav_little;
	}
	return (0);
}
