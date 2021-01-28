/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:44:44 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/12 19:23:46 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*sav_d;
	const char	*sav_s;
	int			n;
	int			length_dst;

	sav_d = dst;
	sav_s = src;
	n = size;
	while (n-- != 0 && *sav_d != '\0')
		sav_d++;
	length_dst = sav_d - dst;
	n = size - length_dst;
	if (n == 0)
		return (length_dst + ft_strlen(sav_s));
	while (*sav_s != '\0')
	{
		if (n != 1)
		{
			*sav_d++ = *sav_s;
			n--;
		}
		sav_s++;
	}
	*sav_d = '\0';
	return (length_dst + sav_s - src);
}
