/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:46:58 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/15 10:09:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
	{
		if (!(new_str = ft_calloc(len + 1, sizeof(char))))
			return (0);
		*new_str = '\0';
		return (new_str);
	}
	if (!(new_str = ft_calloc(len + 1, sizeof(char))))
		return (0);
	ft_strlcpy(new_str, s + start, len + 1);
	return (new_str);
}
