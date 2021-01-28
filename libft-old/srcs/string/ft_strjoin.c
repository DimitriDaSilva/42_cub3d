/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:17:23 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/15 10:08:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	new_str_size;
	char	*new_str;

	if (!s1 || !s2)
		return (0);
	new_str_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new_str = malloc(new_str_size * sizeof(char))))
		return (0);
	ft_strlcpy(new_str, s1, new_str_size);
	ft_strlcat(new_str, s2, new_str_size);
	return (new_str);
}
