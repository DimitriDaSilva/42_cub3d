/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:24:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/22 16:42:19 by dds              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len_float(long double nb)
{
	if (-10 < nb && 1 / nb < 0)
		return (2);
	else if (0 <= nb && nb < 10)
		return (1);
	return (1 + get_len_float(nb / 10));
}
