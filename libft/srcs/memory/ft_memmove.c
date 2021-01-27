/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:52:53 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/13 15:47:01 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*sav_dest;
	void	*sav_src;

	sav_dest = dest;
	sav_src = (void *)src;
	if (dest < src && dest + n >= src)
	{
		while (n--)
			*(char *)sav_dest++ = *(char *)src++;
	}
	else if (src < dest && src + n > dest)
	{
		sav_src += n;
		sav_dest += n;
		while (n--)
			*(char *)--sav_dest = *(char *)--sav_src;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
