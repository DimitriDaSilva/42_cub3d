/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:25:20 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/13 18:45:21 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = malloc(sizeof(void *));
	if (nmemb == 0 || size == 0)
		return (mem);
	if (!(mem = malloc(nmemb * size)))
		return (0);
	ft_memset(mem, '\0', nmemb * size);
	return (mem);
}
