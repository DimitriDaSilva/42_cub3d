/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:32:24 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/05 19:23:39 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_ray.h"

void	cast_ray(t_ray *ray, t_map *map, t_player *player)
{
	t_ray	hrzn_intersection;
	t_ray	vrtl_intersection;

	hrzn_intersection.angle = normalize_radian(ray->angle);
	vrtl_intersection.angle = normalize_radian(ray->angle);
	get_hrzn_intersection(&hrzn_intersection, map, player);
	get_vrtl_intersection(&vrtl_intersection, map, player);
	if (hrzn_intersection.size <= vrtl_intersection.size)
		*ray = hrzn_intersection;
	else
		*ray = vrtl_intersection;
}

double	normalize_radian(double radian)
{
	double	full_circle;

	full_circle = deg_to_rad(360);
	radian = fmod(radian, full_circle);
	if (radian < 0)
		radian += full_circle;
	return (radian);
}