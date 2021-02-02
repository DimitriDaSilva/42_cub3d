/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:58:57 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/02 11:43:44 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_colors.h"

int		add_shade(double distance, int color)
{
	int alpha;

	alpha = distance * (double)(255);
	return (create_argb(alpha, get_r(color), get_g(color), get_b(color)));
}

int		get_opposite(int color)
{
	return (create_argb(get_a(color),
				get_r(0xFF0000) - get_r(color),
				get_g(0x00FF00) - get_g(color),
				get_b(0x0000FF) - get_b(color)));
}
