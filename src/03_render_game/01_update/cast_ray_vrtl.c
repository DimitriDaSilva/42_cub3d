/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_vrtl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:58:40 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/23 18:55:42 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_ray_vrtl.h"

/*
** On a grid, checks all vertical intersections of the ray casted and stores
** the distance between player and wall hit
** @param:	- [t_ray *] ray struct with x, y, size, angle, etc.
**			- [t_map *] map formatted in a 2d array of chars
**			- [t_player *] player to get its position in the grid
** Line-by-line comments:
** @1-5		Edge cases: player oriented straight south or north. For
**			raycasting, it means that the ray will be parallel to the grid
**			lines and will never find an intersection. We give him a very
**			height value so that it rules it out as the shortest ray
** @7-10	2 cases based on the orientation of the ray need to be taken into
**			account. The two functions are very similar but different enough to
**			justify the existence of each. Here readability > maintanability
*/

void	get_vrtl_intersection(t_ray *ray, t_map *map, t_player *player)
{
	ray->size = 0;
	if (ray->angle == deg_to_rad(90) || ray->angle == deg_to_rad(270))
	{
		ray->size = INT_MAX;
		return ;
	}
	if (is_west(ray->angle))
		get_vrtl_intersection_west(ray, map, player);
	else
		get_vrtl_intersection_east(ray, map, player);
}

/*
** Two part algorithm:
** 1. Getting the distance between player and first intersection and check
** if wall hit.
** 2. All subsequent intersection are at a regular step so we need to find it
** and increment until a wall is hit (aka DDA - Digital Differential Analysis)
** @param:	- [t_ray *] ray being casted
**			- [t_map *] map formatted in a 2d array of chars
**			- [t_player *] player to get its position in the grid
** Line-by-line comments:
** @7-13	1st part of the algorithm
** @14-22	2nd part of the algorithm
** @15-16	Cos / tan / sin / sqrt are taxing in the processor so we use them
**			only once and store the result to do the DDA
*/

/*
** get_vrtl_intersection_west() specific comments (go up for general comments):
** @7		We need to round down to get the next vertical intersection
** @8		Float minus rounded down value gets us the straight distance to
**			the vertical intersection
** @10		Taking a step backwards because we are moving from right to left
** @12-13	We need to adjust the value checked to be on the value and not on
**			the edge of it. Same for line 17
** @14		Step needs to negative because we are moving from right to left on
**			the grid
*/

void	get_vrtl_intersection_west(t_ray *ray, t_map *map, t_player *player)
{
	double	a_x;
	double	a_y;
	double	x_step;
	double	y_step;
	double	ray_section;

	a_x = floor(player->x);
	x_step = player->x - a_x;
	y_step = x_step * tan(ray->angle);
	a_y = player->y - y_step;
	ray->size += sqrt(pow(x_step, 2) + pow(y_step, 2));
	if (is_wall(map, a_x - 1, a_y, ray))
		return ;
	x_step = -1;
	y_step = x_step * tan(ray->angle);
	ray_section = sqrt(pow(x_step, 2) + pow(y_step, 2));
	while (!is_wall(map, a_x - 1, a_y, ray))
	{
		a_x += x_step;
		a_y += y_step;
		ray->size += ray_section;
	}
}

/*
** get_vrtl_intersection_east() specific comments (go up for general comments):
** @7		We need to round up to get the next vertical intersection
** @8		Rounded up value minus float one gets us the straight distance to
**			the vertical intersection
** @10		Taking a step forward because we are moving from left to right
** @14		Step needs to positive because we are moving from left to right on
**			the grid
*/

void	get_vrtl_intersection_east(t_ray *ray, t_map *map, t_player *player)
{
	double	a_x;
	double	a_y;
	double	x_step;
	double	y_step;
	double	ray_section;

	a_x = ceil(player->x);
	x_step = a_x - player->x;
	y_step = x_step * tan(ray->angle);
	a_y = player->y + y_step;
	ray->size += sqrt(pow(x_step, 2) + pow(y_step, 2));
	if (is_wall(map, a_x, a_y, ray))
		return ;
	x_step = 1;
	y_step = x_step * tan(ray->angle);
	ray_section = sqrt(pow(x_step, 2) + pow(y_step, 2));
	while (!is_wall(map, a_x, a_y, ray))
	{
		a_x += x_step;
		a_y += y_step;
		ray->size += ray_section;
	}
}
