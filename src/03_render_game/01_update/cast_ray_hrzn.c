/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_hrzn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:58:40 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/12 20:17:31 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_ray_hrzn.h"

/*
** On a grid, checks all horizontal intersections of the ray casted and stores
** the distance between player and wall hit
** @param:	- [t_ray *] ray struct with x, y, size, angle, etc.
**			- [t_map *] map formatted in a 2d array of chars
**			- [t_player *] player to get its position in the grid
** Line-by-line comments:
** @1-5		Edge cases: player oriented straight west or east. For
**			raycasting, it means that the ray will be parallel to the grid
**			lines and will never find an intersection. We give him a very
**			height value so that it rules it out as the shortest ray
** @7-10	2 cases based on the orientation of the ray need to be taken into
**			account. The two functions are very similar but different enough to
**			justify the existence of each. Here readability > maintanability
*/

void	get_hrzn_intersection(t_ray *ray, t_map *map, t_player *player)
{
	ray->size = 0;
	if (ray->angle == deg_to_rad(180) || ray->angle == deg_to_rad(360))
	{
		ray->size = INT_MAX;
		return ;
	}
	if (is_south(ray->angle))
		get_hrzn_intersection_south(ray, map, player);
	else
		get_hrzn_intersection_north(ray, map, player);
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
** get_hrzn_intersection_south() specific comments (go up for general comments):
** @7		We need to round up to get the next horizontal intersection
** @8		Rounded up value minus float one gets us the straight distance to
**			the horizontal intersection 
** @10		Taking a step forward because we are moving from up to down
** @14		Step needs to positive because we are moving from up to down on
**			the grid
*/

void	get_hrzn_intersection_south(t_ray *ray, t_map *map, t_player *player)
{
	double	a_x;
	double	a_y;
	double	x_step;
	double	y_step;
	double	ray_section;

	a_y = ceil(player->y);
	y_step = a_y - player->y;
	x_step = y_step / tan(ray->angle);
	a_x = player->x + x_step;
	ray->size += sqrt(pow(x_step, 2) + pow(y_step, 2));
	if (is_wall(map, a_x, a_y, ray))
		return ;
	y_step = 1;
	x_step = y_step / tan(ray->angle);
	ray_section = sqrt(pow(x_step, 2) + pow(y_step, 2));
	while (!is_wall(map, a_x, a_y, ray))
	{
		a_x += x_step;
		a_y += y_step;
		ray->size += ray_section;
	}
}

/*
** get_hrzn_intersection_north() specific comments (go up for general comments):
** @7		We need to round down to get the next horizontal intersection
** @8		Float minus rounded down value gets us the straight distance to
**			the horizontal intersection 
** @10		Taking a step backwards because we are moving from down to up
** @12-13	We need to adjust the value checked to be on the value and not on
**			the edge of it. Same for line 17
** @14		Step needs to negative because we are moving from down to up on
**			the grid
*/

void	get_hrzn_intersection_north(t_ray *ray, t_map *map, t_player *player)
{
	double	a_x;
	double	a_y;
	double	x_step;
	double	y_step;
	double	ray_section;

	a_y = floor(player->y);
	y_step = player->y - a_y;
	x_step = y_step / tan(ray->angle);
	a_x = player->x - x_step;
	ray->size += sqrt(pow(x_step, 2) + pow(y_step, 2));
	if (is_wall(map, a_x, a_y - 1, ray))
		return ;
	y_step = -1;
	x_step = +y_step / tan(ray->angle);
	ray_section = sqrt(pow(x_step, 2) + pow(y_step, 2));
	while (!is_wall(map, a_x, a_y - 1, ray))
	{
		a_x += x_step;
		a_y += y_step;
		ray->size += ray_section;
	}
}
