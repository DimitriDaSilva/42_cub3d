/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:58:57 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/26 19:02:00 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_colors.h"

int		add_shade(double distance, int color)
{
	int shade;

	shade = distance * (double)(255);
	return (create_trgb(shade, get_r(color), get_g(color), get_b(color)));
}

int		get_opposite(int color)
{
	return (create_trgb(get_t(color),
				255 - get_r(color),
				255 - get_g(color),
				255 - get_b(color)));
}
