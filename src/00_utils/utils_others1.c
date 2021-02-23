/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 08:43:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:53:05 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_others.h"

void	unload_strs(char **strs)
{
	while (*strs)
		free(*strs++);
}

double	rad_to_deg(double rad)
{
	return (rad * 180.0 / M_PI);
}

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

/*
** Makes sure the radian stays between 0 and 2 * PI
** @param:	- [double] radian
** @return:	[double] radian normalized
*/

double	normalize_radian(double radian)
{
	double	full_circle;

	full_circle = deg_to_rad(360);
	radian = fmod(radian, full_circle);
	if (radian < 0)
		radian += full_circle;
	return (radian);
}

int		create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}
