/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:44:09 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/13 11:08:45 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		s_len;
	char	*end_s;

	s_len = ft_strlen(s);
	end_s = (char *)s + s_len;
	if (c == 0)
		return (end_s);
	while (*s != *end_s--)
	{
		if (*end_s == c)
			return (end_s);
	}
	return (0);
}
