/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:32:24 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 18:06:10 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_ray.h"

/*
** Casts 2 rays to find the distance between player and wall. One ray checks
** the horizontal grid intersection and the other the vertical ones. The 
** shortest ray is kept as the distance between player and wall to determine
** the height of the wall
** @param:	- [t_ray *] ray being casted
**			- [t_map *] map struct reprensenting the 2D view of the map
**			- [t_player *] player struct with position, rotation_angle, etc.
** Line-by-line comments:
** @4-5		Makes sure the angle is between 0 and 2 * PI
** @6-7		The information is valuable for finding the bitmap offset (which
**			part of the texture to show at specific pixel in the wall)
*/

void	cast_ray(t_ray *ray, t_map *map, t_player *player)
{
	t_ray	hrzn_intersection;
	t_ray	vrtl_intersection;

	hrzn_intersection.angle = normalize_radian(ray->angle);
	vrtl_intersection.angle = normalize_radian(ray->angle);
	hrzn_intersection.side = 'H';
	vrtl_intersection.side = 'V';
	get_hrzn_intersection(&hrzn_intersection, map, player);
	get_vrtl_intersection(&vrtl_intersection, map, player);
	if (hrzn_intersection.size <= vrtl_intersection.size)
		*ray = hrzn_intersection;
	else
		*ray = vrtl_intersection;
}
